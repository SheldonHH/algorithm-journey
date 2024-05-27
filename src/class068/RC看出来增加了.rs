use std::cell::RefCell;
use std::rc::Rc;

#[derive(Debug)]
struct TreeNode {
    val: i32,
    left: Option<Rc<RefCell<TreeNode>>>,
    right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    fn new(val: i32) -> Rc<RefCell<TreeNode>> {
        Rc::new(RefCell::new(TreeNode {
            val,
            left: None,
            right: None,
        }))
    }
}

fn main() {
    let root = TreeNode::new(1);
    let left_child = TreeNode::new(2);
    let right_child = TreeNode::new(3);

    // 设置左子节点和右子节点
    root.borrow_mut().left = Some(left_child.clone());
    root.borrow_mut().right = Some(right_child.clone());

    // 查看 root 的引用计数
    println!("Initial root strong count: {}", Rc::strong_count(&root));

    let root_clone = root.clone();
    println!("After cloning root strong count: {}", Rc::strong_count(&root));
    println!("root_clone strong count: {}", Rc::strong_count(&root_clone));

    if let Some(left) = &root.borrow().left {
        println!("Initial left strong count: {}", Rc::strong_count(left));
        let left_clone = left.clone();
        println!("After cloning left strong count: {}", Rc::strong_count(left));
        println!("left_clone strong count: {}", Rc::strong_count(&left_clone));
    }
}
