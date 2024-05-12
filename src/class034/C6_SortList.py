# 排序链表
# 要求时间复杂度O(n*logn)，额外空间复杂度O(1)，还要求稳定性

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def sort_list(head):
    # 计算链表长度
    def get_length(node):
        length = 0
        while node:
            length += 1
            node = node.next
        return length

    # 找到链表中某段的尾部，返回起点s往下数k个节点
    def find_end(s, k):
        while s and s.next and k > 1:
            s = s.next
            k -= 1
        return s

    # 合并两段有序链表
    def merge(l1, r1, l2, r2):
        if not l1:
            return l2, r2
        if not l2:
            return l1, r1

        start = end = None
        if l1.val <= l2.val:
            start = end = l1
            l1 = l1.next
        else:
            start = end = l2
            l2 = l2.next

        while l1 and l2:
            if l1.val <= l2.val:
                end.next = l1
                end = l1
                l1 = l1.next
            else:
                end.next = l2
                end = l2
                l2 = l2.next

        if l1:
            end.next = l1
            end = r1
        else:
            end.next = l2
            end = r2

        return start, end

    n = get_length(head)

    for step in range(1, n, step := step * 2):
        l1 = head
        last_team_end = None

        while l1:
            r1 = find_end(l1, step)
            l2 = r1.next if r1 else None
            if not l2:
                if last_team_end:
                    last_team_end.next = l1
                break

            r2 = find_end(l2, step)
            next = r2.next if r2 else None

            r1.next = None
            r2.next = None

            merged_start, merged_end = merge(l1, r1, l2, r2)
            
            if last_team_end:
                last_team_end.next = merged_start
            else:
                head = merged_start

            last_team_end = merged_end

            l1 = next

    return head
