class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverseKGroup(head, k):
    def team_end(s, k):
        """当前组的开始节点是s，往下数k个找到当前组的结束节点返回"""
        while k - 1 > 0 and s is not None:
            s = s.next
            k -= 1
        return s

    def reverse(s, e):
        """s -> a -> b -> c -> e -> 下一组的开始节点
        上面的链表通过如下的reverse方法调整成 : e -> c -> b -> a -> s -> 下一组的开始节点"""
        e = e.next
        prev = None
        cur = s
        while cur is not e:
            next_node = cur.next
            cur.next = prev
            prev = cur
            cur = next_node
        s.next = e

    start = head
    end = team_end(start, k)
    if end is None:
        return head
    # 第一组很特殊因为牵扯到换头的问题
    head = end
    reverse(start, end)
    # 翻转之后start变成了上一组的结尾节点
    last_team_end = start
    while last_team_end.next is not None:
        start = last_team_end.next
        end = team_end(start, k)
        if end is None:
            return head
        reverse(start, end)
        last_team_end.next = end
        last_team_end = start

    return head

# 您可以在这里添加测试代码来检查功能的正确性。
def print_list(head):
    """打印链表"""
    while head:
        print(head.val, end=" -> ")
        head = head.next
    print("None")

# 示例测试代码
if __name__ == "__main__":
    # 构建一个链表用于测试
    nodes = [ListNode(i) for i in range(1, 6)]
    for i in range(4):
        nodes[i].next = nodes[i + 1]
    
    head = nodes[0]
    
    print("原链表:")
    print_list(head)
    
    k = 2
    head = reverseKGroup(head, k)
    
    print(f"每{k}个节点一组翻转后的链表:")
    print_list(head)
