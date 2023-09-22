#[derive(Debug, PartialEq, Eq, Clone)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        ListNode {
            val,
            next: None,
        }
    }
}

fn reverse_k_group(mut head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
    let mut count = 0;
    let mut ptr = &head;
    while let Some(node) = ptr {
        count += 1;
        if count >= k {
            break;
        }
        ptr = &node.next;
    }

    if count < k {
        return head;
    }

    let mut prev: Option<Box<ListNode>> = None;
    let mut current = head;
    let mut next: Option<Box<ListNode>>;
    let mut count = k;

    while count > 0 {
        next = current.clone().unwrap().next.clone();
        current.clone().unwrap().next = prev;
        prev = current;
        current = next;
        count -= 1;
    }
    head.unwrap().next = reverse_k_group(current, k);
    prev
}

fn main() {
    let mut head = Some(Box::new(ListNode::new(1)));
    head.as_mut().unwrap().next = Some(Box::new(ListNode::new(2)));
    head.as_mut().unwrap().next.as_mut().unwrap().next = Some(Box::new(ListNode::new(3)));
    head.as_mut().unwrap().next.as_mut().unwrap().next.as_mut().unwrap().next = Some(Box::new(ListNode::new(4)));
    head.as_mut().unwrap().next.as_mut().unwrap().next.as_mut().unwrap().next.as_mut().unwrap().next = Some(Box::new(ListNode::new(5)));

    println!("Initial list: {:?}", head);

    let reversed_head = reverse_k_group(head, 2);

    println!("Reversed list: {:?}", reversed_head);
}

