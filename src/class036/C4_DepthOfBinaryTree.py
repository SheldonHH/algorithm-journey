class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # 测试链接 : https://leetcode.cn/problems/maximum-depth-of-binary-tree/
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            # 当前的树是空树
            return 0
        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1

    # 测试链接 : https://leetcode.cn/problems/minimum-depth-of-binary-tree/
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            # 当前的树是空树
            return 0
        if not root.left and not root.right:
            # 当前root是叶节点
            return 1
        
        # 初始化左右子树的最小深度为一个很大的数
        min_left = float('inf')
        min_right = float('inf')

        if root.left:
            min_left = self.minDepth(root.left)
        if root.right:
            min_right = self.minDepth(root.right)
        
        return min(min_left, min_right) + 1
