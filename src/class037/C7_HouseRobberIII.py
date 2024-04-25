class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Code07_HouseRobberIII:
    def rob(self, root):
        res = self.f(root)
        return max(res[0], res[1])

    def f(self, root):
        if root is None:
            return (0, 0)
        left = self.f(root.left)
        right = self.f(root.right)
        # 当前节点选择偷，下一个就不能偷
        yes = root.val + left[1] + right[1]
        # 当前节点选择不偷，下一个可以偷或不偷，选择一个较大的
        no = max(left[0], left[1]) + max(right[0], right[1])
        return (yes, no)

# 使用中文注释来描述代码的功能和逻辑
