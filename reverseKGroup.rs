use std::option::Option::{None, Some};

#[derive(Debug)]
struct ListNode {
    val: i32,
    next: Option<Box<ListNode>>,
}

impl ListNode {
    fn new(val: i32) -> Self {
        ListNode { val, next: None }
    }
}

fn reverse_k_group(mut head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
    let mut dummy = Box::new(ListNode::new(0));
    dummy.next = head;

    let mut count = 0;
    let mut cur = dummy.next.as_ref();
    while let Some(_) = cur {
        count += 1;
        cur = cur.unwrap().next.as_ref();
    }

    let mut pre = dummy.clone();
    let mut count = count;
    let mut pre_mut_ref = &mut dummy.next;
    while count >= k {
        let mut cur_mut_ref = pre_mut_ref;
        let mut nex = cur_mut_ref.as_mut().unwrap().next.take();
        for _ in 1..k {
            cur_mut_ref.as_mut().unwrap().next = nex.as_mut().unwrap().next.take();
            nex.as_mut().unwrap().next = pre_mut_ref.take();
            *pre_mut_ref = Some(nex.take().unwrap());
            nex = cur_mut_ref.as_mut().unwrap().next.take();
        }
        pre_mut_ref = &mut cur_mut_ref.as_mut().unwrap().next;
        count -= k;
    }
    dummy.next
}

fn print_list(mut head: Option<Box<ListNode>>) {
    while let Some(mut node) = head {
        print!("{} ", node.val);
        head = node.next.take();
    }
    println!();
}

fn main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> None
    let mut head = Some(Box::new(ListNode::new(1)));
    head.as_mut().unwrap().next = Some(Box::new(ListNode::new(2)));
    head.as_mut().unwrap().next.as_mut().unwrap().next = Some(Box::new(ListNode::new(3)));
    head.as_mut().unwrap().next.as_mut().unwrap().next.as_mut().unwrap().next = Some(Box::new(ListNode::new(4)));
    head.as_mut().unwrap().next.as_mut().unwrap().next.as_mut().unwrap().next.as_mut().unwrap().next = Some(Box::new(ListNode::new(5)));
    head.as_mut().unwrap().next.as_mut().unwrap().next.as_mut().unwrap().next.as_mut().unwrap().next.as_mut().unwrap().next = Some(Box::new(ListNode::new(6)));

    println!("Original list: ");
    print_list(head.clone());

    let k = 3;
    let new_head = reverse_k_group(head, k);

    println!("List after reversing every {} nodes: ", k);
    print_list(new_head);
}

