class TreeNode:  
    def __init__(self, v):  
        self.val = v  
        self.left = None  
        self.right = None  
  
def pre_order(head):  
    """先序遍历（非递归实现）"""  
    if head:  
        stack = [head]  
        while stack:  
            node = stack.pop()  
            print(node.val, end=' ')  
            if node.right:  
                stack.append(node.right)  
            if node.left:  
                stack.append(node.left)  
        print()  
  
def in_order(head):  
    """中序遍历（非递归实现）"""  
    stack = []  
    while stack or head:  
        if head:  
            stack.append(head)  
            head = head.left  
        else:  
            head = stack.pop()  
            print(head.val, end=' ')  
            head = head.right  
    print()  
  
def pos_order_two_stacks(head):  
    """后序遍历，使用两个栈（非递归实现）"""  
    if head:  
        stack1 = [head]  
        stack2 = []  
        while stack1:  
            node = stack1.pop()  
            stack2.append(node)  
            if node.left:  
                stack1.append(node.left)  
            if node.right:  
                stack1.append(node.right)  
        while stack2:  
            node = stack2.pop()  
            print(node.val, end=' ')  
        print()  
  

# 后序打印所有节点，非递归版
# 这是用一个栈的方法
def pos_order_one_stack(h):
    if h is not None:
        stack = []
        stack.append(h)
        # 如果始终没有打印过节点，h就一直是头节点
        # 一旦打印过节点，h就变成打印节点
        # 之后h的含义 : 上一次打印的节点
        while stack:
            cur = stack[-1] # stack.peek()
            if cur.left is not None and h != cur.left and h != cur.right:
                # 有左树且左树没处理过
                stack.append(cur.left)
            elif cur.right is not None and h != cur.right:
                # 有右树且右树没处理过
                stack.append(cur.right)
            else:
                # 左树、右树 没有 或者 都处理过了
                print(cur.val, end=" ")
                h = stack.pop()
        print()
  
# 创建二叉树  
root = TreeNode(1)  
root.left = TreeNode(2)  
root.right = TreeNode(3)  
root.left.left = TreeNode(4)  
root.left.right = TreeNode(5)  
root.right.left = TreeNode(6)  
root.right.right = TreeNode(7)  
  
# 执行遍历  
pre_order(root)  
print("先序遍历非递归版")  
in_order(root)  
print("中序遍历非递归版")  
pos_order_two_stacks(root)  
print("后序遍历非递归版 - 2个栈实现")  
pos_order_one_stack(root)  
print("后序遍历非递归版 - 1个栈实现")  