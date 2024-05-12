class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 使用先序与中序遍历序列构造二叉树
def buildTree(preorder, inorder):
    if not preorder or not inorder or len(preorder) != len(inorder):
        return None
    
    # 创建哈希映射以优化查找速度
    idx_map = {value: idx for idx, value in enumerate(inorder)}
    
    # 辅助函数，通过递归构造子树
    def construct(left, right):
        if left > right:
            return None
        
        # 根节点为先序遍历的第一个元素
        root_value = preorder.pop(0)
        root = TreeNode(root_value)
        
        # 根据根节点在中序遍历中的位置，分割左右子树
        index = idx_map[root_value]
        
        # 构造左子树和右子树
        root.left = construct(left, index - 1)
        root.right = construct(index + 1, right)
        
        return root
    
    return construct(0, len(inorder) - 1)
