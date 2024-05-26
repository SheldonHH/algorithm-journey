use std::collections::HashMap;
use std::rc::Rc; // Rc 提供引用计数的智能指针，使得多个所有者可以共享数据
use std::cell::RefCell; // RefCell 允许在运行时对数据进行可变借用检查，实现内部可变性，即在不可变对象内部改变其内容

struct LRUCache {
    capacity: usize,
    map: RefCell<HashMap<i32, Rc<RefCell<DoubleNode>>>>, // RefCell 包裹 HashMap 允许在不可变引用下进行可变操作
    head: RefCell<Link>, // RefCell 包裹 Option，允许对链表头进行可变操作
    tail: RefCell<Link>, // RefCell 包裹 Option，允许对链表尾进行可变操作
}

type Link = Option<Rc<RefCell<DoubleNode>>>; // Option 表示链表节点的存在或不存在，Rc 提供多重所有权，RefCell 允许内部可变性

struct DoubleNode {
    key: i32,
    value: i32,
    prev: Link, // Option<Rc<RefCell<DoubleNode>>> 表示前驱节点，可以为 None
    next: Link, // Option<Rc<RefCell<DoubleNode>>> 表示后继节点，可以为 None
}

impl LRUCache {
    fn new(capacity: i32) -> Self {
        LRUCache {
            capacity: capacity as usize,
            map: RefCell::new(HashMap::new()),
            head: RefCell::new(None),
            tail: RefCell::new(None),
        }
    }

    fn get(&self, key: i32) -> i32 {
        if let Some(node) = self.map.borrow().get(&key) {
            let node = Rc::clone(node);
            self.move_to_tail(&node); // 🌟+解释：传递节点引用而不是所有权
            return node.borrow().value;
        }
        -1
    }

    fn put(&self, key: i32, value: i32) {
        if let Some(node) = self.map.borrow().get(&key) {
            let node = Rc::clone(node);
            node.borrow_mut().value = value;
            self.move_to_tail(&node); // 🌟+解释：传递节点引用而不是所有权
        } else {
            if self.map.borrow().len() == self.capacity {
                self.remove_head();
            }
            let new_node = Rc::new(RefCell::new(DoubleNode {
                key,
                value,
                prev: None,
                next: None,
            }));
            self.add_node(new_node.clone());
            self.map.borrow_mut().insert(key, new_node);
        }
    }

    fn add_node(&self, node: Rc<RefCell<DoubleNode>>) { // 🌟+解释：新增 add_node 函数，将新节点添加到链表尾部
        if let Some(tail) = self.tail.borrow_mut().take() {
            tail.borrow_mut().next = Some(node.clone());
            node.borrow_mut().prev = Some(tail);
        } else {
            *self.head.borrow_mut() = Some(node.clone());
        }
        *self.tail.borrow_mut() = Some(node);
    }

    fn move_to_tail(&self, node: &Rc<RefCell<DoubleNode>>) { // 🌟+解释：修改为传递节点的引用
        if self.tail.borrow().as_ref().map(|tail| Rc::ptr_eq(&tail, node)).unwrap_or(false) {
            return;
        }
        let (prev, next) = {
            let mut node_borrow = node.borrow_mut();
            (node_borrow.prev.take(), node_borrow.next.take())
        };
        if let Some(ref prev) = prev { // 🌟+解释：使用引用来避免移动值
            prev.borrow_mut().next = next.clone();
        } else {
            *self.head.borrow_mut() = next.clone();
        }
        if let Some(ref next) = next { // 🌟+解释：使用引用来避免移动值
            next.borrow_mut().prev = prev.clone();
        } else {
            *self.tail.borrow_mut() = prev.clone();
        }
        self.add_node(node.clone()); // 🌟+解释：传递节点的克隆
    }

    fn remove_head(&self) {
        if let Some(head) = self.head.borrow_mut().take() {
            self.map.borrow_mut().remove(&head.borrow().key);
            *self.head.borrow_mut() = head.borrow_mut().next.take();
            if let Some(new_head) = self.head.borrow().as_ref() {
                new_head.borrow_mut().prev = None;
            } else {
                *self.tail.borrow_mut() = None;
            }
        }
    }
}