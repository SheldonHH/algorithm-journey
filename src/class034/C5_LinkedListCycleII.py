# 复制带随机指针的链表
# 测试链接 : https://leetcode-cn/problems/copy-list-with-random-pointer/
class Node:
    def __init__(self, val=0, next=None, random=None):
        self.val = val
        self.next = next
        self.random = random

def copyRandomList(head):
    if not head:
        return None
    cur = head
    next = None
    # 1 -> 2 -> 3 -> ...
    # 变成 : 1 -> 1' -> 2 -> 2' -> 3 -> 3' -> ...
    while cur:
        next = cur.next
        cur.next = Node(cur.val)
        cur.next.next = next
        cur = next
    cur = head
    copy = None
    # 利用上面新老节点的结构关系，设置每一个新节点的random指针
    while cur:
        next = cur.next.next
        copy = cur.next
        copy.random = cur.random.next if cur.random else None
        cur = next
    ans = head.next
    cur = head
    # 新老链表分离 : 老链表重新连在一起，新链表重新连在一起
    while cur:
        next = cur.next.next
        copy = cur.next
        cur.next = next
        copy.next = next.next if next else None
        cur = next
    # 返回新链表的头节点
    return ans

# For testing purpose, not to be submitted.
if __name__ == "__main__":
    # Test cases can be added here.
    pass
