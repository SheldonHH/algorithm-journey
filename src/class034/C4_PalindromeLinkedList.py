class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def is_palindrome(head: ListNode) -> bool:
    # 若链表为空或只有一个节点，则必定是回文
    if not head or not head.next:
        return True
    # 找中点
    slow, fast = head, head
    while fast.next and fast.next.next:
        slow = slow.next
        fast = fast.next.next

    # 中点是slow，开始将后半部分逆序
    pre = slow # 中点
    cur = pre.next # 中点下一个
    pre.next = None # 中点指向空
    while cur:    # 中点下一个
        next = cur.next # 
        cur.next = pre
        pre = cur       # pre
        cur = next      # 

    # 现在链表的形式是：head -> ... -> slow <- ... <- pre
    left = head
    right = pre
    ans = True

    # 比较左右两侧的值
    while left and right:
        if left.val != right.val:
            ans = False
            break
        left = left.next
        right = right.next

    # 把链表恢复原状
    cur = pre.next
    pre.next = None
    while cur:
        next = cur.next
        cur.next = pre
        pre = cur
        cur = next

    return ans
