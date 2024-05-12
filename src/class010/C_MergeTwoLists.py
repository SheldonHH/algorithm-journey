# 将两个升序链表合并为一个新的 升序 链表并返回
# 新链表是通过拼接给定的两个链表的所有节点组成的
# 测试链接: https://leetcode.cn/problems/merge-two-sorted-lists/

from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # 如果其中一个链表为空，则返回另一个链表
        if l1 is None or l2 is None:
            return l2 if l1 is None else l1

        # 确定新的链表的头节点以及初始遍历指针
        if l1.val <= l2.val:
            head = l1
            c1 = l1.next
            c2 = l2
        else:
            head = l2
            c1 = l1
            c2 = l2.next

        pre = head

        # 合并两个链表
        while c1 is not None and c2 is not None:
            if c1.val <= c2.val:
                pre.next = c1
                c1 = c1.next
            else:
                pre.next = c2
                c2 = c2.next

            pre = pre.next

        # 将剩余的链表节点拼接到新的链表后面
        pre.next = c1 if c1 is not None else c2

        return head
