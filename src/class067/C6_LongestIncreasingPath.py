class Code06_LongestIncreasingPath:
    # 矩阵中的最长递增路径
    # 给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度
    # 对于每个单元格，你可以往上，下，左，右四个方向移动
    # 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）
    # 测试链接 : https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/

    def longestIncreasingPath1(self, grid):
        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                ans = max(ans, self.f1(grid, i, j))
        return ans

    # 从(i,j)出发，能走出来多长的递增路径，返回最长长度
    def f1(self, grid, i, j):
        next_val = 0
        if i > 0 and grid[i][j] < grid[i - 1][j]:
            next_val = max(next_val, self.f1(grid, i - 1, j))
        if i + 1 < len(grid) and grid[i][j] < grid[i + 1][j]:
            next_val = max(next_val, self.f1(grid, i + 1, j))
        if j > 0 and grid[i][j] < grid[i][j - 1]:
            next_val = max(next_val, self.f1(grid, i, j - 1))
        if j + 1 < len(grid[0]) and grid[i][j] < grid[i][j + 1]:
            next_val = max(next_val, self.f1(grid, i, j + 1))
        return next_val + 1

    def longestIncreasingPath2(self, grid):
        n = len(grid)
        m = len(grid[0])
        dp = [[0] * m for _ in range(n)]
        ans = 0
        for i in range(n):
            for j in range(m):
                ans = max(ans, self.f2(grid, i, j, dp))
        return ans

    def f2(self, grid, i, j, dp):
        if dp[i][j] != 0:
            return dp[i][j]
        next_val = 0
        if i > 0 and grid[i][j] < grid[i - 1][j]:
            next_val = max(next_val, self.f2(grid, i - 1, j, dp))
        if i + 1 < len(grid) and grid[i][j] < grid[i + 1][j]:
            next_val = max(next_val, self.f2(grid, i + 1, j, dp))
        if j > 0 and grid[i][j] < grid[i][j - 1]:
            next_val = max(next_val, self.f2(grid, i, j - 1, dp))
        if j + 1 < len(grid[0]) and grid[i][j] < grid[i][j + 1]:
            next_val = max(next_val, self.f2(grid, i, j + 1, dp))
        dp[i][j] = next_val + 1
        return next_val + 1
