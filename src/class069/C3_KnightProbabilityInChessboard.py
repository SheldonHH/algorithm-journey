class Code03_KnightProbabilityInChessboard:
    def knight_probability(self, n, k, row, col):
        # 创建一个三维数组，用来存储动态规划的结果
        dp = [[[-1 for _ in range(k + 1)] for _ in range(n)] for _ in range(n)]
        return self.f(n, row, col, k, dp)

    # 从(i, j)出发还有k步要走，返回最后在棋盘上的概率
    def f(self, n, i, j, k, dp):
        # 检查坐标是否出界
        if i < 0 or i >= n or j < 0 or j >= n:
            return 0
        # 如果这个状态已经计算过，则直接返回结果
        if dp[i][j][k] != -1:
            return dp[i][j][k]
        # 如果没有步数可走，返回1（因为它仍然在棋盘上）
        if k == 0:
            ans = 1
        else:
            # 否则计算所有可能的移动
            ans = (self.f(n, i - 2, j + 1, k - 1, dp) +
                   self.f(n, i - 1, j + 2, k - 1, dp) +
                   self.f(n, i + 1, j + 2, k - 1, dp) +
                   self.f(n, i + 2, j + 1, k - 1, dp) +
                   self.f(n, i + 2, j - 1, k - 1, dp) +
                   self.f(n, i + 1, j - 2, k - 1, dp) +
                   self.f(n, i - 1, j - 2, k - 1, dp) +
                   self.f(n, i - 2, j - 1, k - 1, dp)) / 8.0
        # 存储计算结果
        dp[i][j][k] = ans
        return ans
