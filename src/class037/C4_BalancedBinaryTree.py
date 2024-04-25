class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    balance = True  # balance是全局变量，所有调用过程共享

    @staticmethod
    def isBalanced(root):
        # 所以每次判断开始时，设置为true
        Solution.balance = True
        Solution.height(root)
        return Solution.balance

    @staticmethod
    def height(cur):
        if not Solution.balance or cur is None:
            return 0
        lh = Solution.height(cur.left)
        rh = Solution.height(cur.right)
        if abs(lh - rh) > 1:
            Solution.balance = False
        return max(lh, rh) + 1

# 测试代码
if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.right = TreeNode(6)
    
    print("Is balanced?", Solution.isBalanced(root))
