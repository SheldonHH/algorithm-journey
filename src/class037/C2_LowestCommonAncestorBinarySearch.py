class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root, p, q):
        """
        寻找二叉搜索树中两个节点的最近公共祖先
        测试链接：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
        """
        # 从root开始向下寻找
        # 如果先遇到了p，说明p就是答案
        # 如果先遇到了q，说明q就是答案
        # 如果root的值在p和q的值之间，说明当前的root就是最近的公共祖先
        # 如果root的值在p和q的值的左侧，那么向右子树移动
        # 如果root的值在p和q的值的右侧，那么向左子树移动
        while root.val != p.val and root.val != q.val:
            if min(p.val, q.val) < root.val < max(p.val, q.val):
                break  # 找到公共祖先
            root = root.right if root.val < min(p.val, q.val) else root.left
        return root
