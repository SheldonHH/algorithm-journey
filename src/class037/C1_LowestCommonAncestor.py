class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def lowestCommonAncestor(root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
    # 如果根节点为空，或者根节点是p或q之一，直接返回根节点
    if root is None or root == p or root == q:
        return root
    
    # 在左子树中查找
    left = lowestCommonAncestor(root.left, p, q)
    # 在右子树中查找
    right = lowestCommonAncestor(root.right, p, q)
    
    # 如果左右子树分别找到了p和q，那么当前根节点就是最近公共祖先
    if left is not None and right is not None:
        return root
    # 如果左右子树都没有找到，返回None
    if left is None and right is None:
        return None
    # 如果左子树或右子树中有一个找到了p或q，返回那个找到的节点
    return left if left is not None else right
