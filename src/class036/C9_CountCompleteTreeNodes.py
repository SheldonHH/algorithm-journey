class TreeNode:
    """ 定义完全二叉树的结构 """
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def countNodes(head):
    """
    计算完全二叉树的节点个数
    """
    if head is None:
        return 0
    return f(head, 1, mostLeft(head, 1))

def f(cur, level, h):
    """
    cur : 当前节点
    level : 当前节点所在的层数
    h : 整棵树的高度，不是当前节点子树的高度
    功能 : 计算当前子树中的节点数
    """
    if level == h:
        return 1
    if mostLeft(cur.right, level + 1) == h:
        # 如果当前节点的右子树的最左边节点能到达最深的层次
        return (1 << (h - level)) + f(cur.right, level + 1, h)
    else:
        # 如果当前节点的右子树的最左边节点没有达到最深的层次
        return (1 << (h - level - 1)) + f(cur.left, level + 1, h)

def mostLeft(cur, level):
    """
    cur : 当前节点
    level : 当前节点所在的层数
    功能 : 返回从当前节点开始一直向左能达到的层数
    """
    while cur:
        level += 1
        cur = cur.left
    return level - 1

# 主函数用于演示
if __name__ == '__main__':
    # 创建树的节点用于测试
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)

    # 计算节点个数
    print("The number of nodes in the complete binary tree is:", countNodes(root))
