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
  
def pos_order_one_stack(head):  
    """后序遍历，使用一个栈（非递归实现）"""  
    stack = []  
    last_print = None  
    while stack or head:  
        if head:  
            stack.append(head)  
            head = head.left  
        else:  
            peek = stack[-1]  
            if peek.right and last_print != peek.right:  
                head = peek.right  
            else:  
                print(peek.val, end=' ')  
                last_print = stack.pop()  
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