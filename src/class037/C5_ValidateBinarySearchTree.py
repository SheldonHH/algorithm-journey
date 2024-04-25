class TreeNode:
    """二叉树节点定义"""
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    # 最大节点数量
    MAXN = 10001

    def __init__(self):
        self.stack = [None] * self.MAXN
        self.r = 0

    def isValidBST1(self, head: TreeNode) -> bool:
        """检验二叉搜索树方法1"""
        if not head:
            return True

        pre = None
        self.r = 0
        while self.r > 0 or head:
            if head:
                self.stack[self.r] = head
                self.r += 1
                head = head.left
            else:
                head = self.stack[self.r - 1]
                self.r -= 1
                if pre and pre.val >= head.val:
                    return False
                pre = head
                head = head.right
        return True

    def isValidBST2(self, head: TreeNode) -> bool:
        """检验二叉搜索树方法2"""
        self.min = float('inf')
        self.max = float('-inf')
        return self._isValidBST_rec(head)

    def _isValidBST_rec(self, node: TreeNode) -> bool:
        if not node:
            return True

        lok = self._isValidBST_rec(node.left)
        lmin = self.min
        lmax = self.max

        rok = self._isValidBST_rec(node.right)
        rmin = self.min
        rmax = self.max

        self.min = min(lmin, rmin
