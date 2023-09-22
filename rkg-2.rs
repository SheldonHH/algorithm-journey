use std::option::Option::Some;

#[derive(Debug, PartialEq, Eq, Clone)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    pub fn new(val: i32) -> Self {
        ListNode {
            next: None,
            val,
        }
    }
}

fn reverse_k_group(mut head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
    let mut curr = head.clone();
    let mut count = 0;
    while let Some(_) = curr {
        count += 1;
        curr = curr.unwrap().next.clone();
    }
    if k > count {
        return head;
    }

    let mut prev: Option<Box<ListNode>> = None;
    let mut curr = head.clone();
    let mut next: Option<Box<ListNode>>;
    let mut count = k;

    while count > 0 {
        next = curr.clone().unwrap().next.clone();
        curr.clone().unwrap().next = prev;
        prev = curr.clone();
        curr = next;
        count -= 1;
    }

    if let Some(mut next_head) = curr {
        head.unwrap().next = reverse_k_group(next_head, k);
    }
    
    prev
}

fn main() {
    // Create a sample list: 1 -> 2 -> 3 -> 4 -> 5
    let mut head = Some(Box::new(ListNode::new(1)));
    head.as_mut().unwrap().next = Some(Box::new(ListNode::new(2)));
    head.as_mut().unwrap().next.as_mut().unwrap().next = Some(Box::new(ListNode::new(3)));
    head.as_mut().unwrap().next.as_mut().unwrap().next.as_mut().unwrap().next = Some(Box::new(ListNode::new(4)));
    head.as_mut().unwrap().next.as_mut().unwrap().next.as_mut().unwrap().next.as_mut().unwrap().next = Some(Box::new(ListNode::new(5)));

    // Print initial list
    println!("Initial list: {:?}", head);

    // Reverse in k-groups and print the reversed list
    let k = 2;
    let reversed_head = reverse_k_group(head, k);
    println!("Reversed list in {}-groups: {:?}", k, reversed_head);
}

