class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Code03_PathSumII:
    def pathSum(self, root, aim):
        """
        收集累加和等于aim的所有路径
        测试链接: https://leetcode.cn/problems/path-sum-ii/
        """
        ans = []
        if root is not None:
            path = []
            self.f(root, aim, 0, path, ans)
        return ans

    def f(self, cur, aim, sum, path, ans):
        if cur.left is None and cur.right is None:
            # 叶节点
            if cur.val + sum == aim:
                path.append(cur.val)
                ans.append(path.copy())
                path.pop()
        else:
            # 不是叶节点
            path.append(cur.val)
            if cur.left is not None:
                self.f(cur.left, aim, sum + cur.val, path, ans)
            if cur.right is not None:
                self.f(cur.right, aim, sum + cur.val, path, ans)
            path.pop()

# 示例使用
if __name__ == "__main__":
    # 构造一个简单的测试树：      5
    #                         /     \
    #                        4       8
    #                       /       / \
    #                      11      13  4
    #                     /  \          \
    #                    7    2          1
    root = TreeNode(5)
    root.left = TreeNode(4)
    root.right = TreeNode(8)
    root.left.left = TreeNode(11)
    root.left.left.left = TreeNode(7)
    root.left.left.right = TreeNode(2)
    root.right.left = TreeNode(13)
    root.right.right = TreeNode(4)
    root.right.right.right = TreeNode(1)

    # 创建实例并调用函数
    solver = Code03_PathSumII()
    result = solver.pathSum(root, 22)
    print("路径总和为22的所有路径:", result)
