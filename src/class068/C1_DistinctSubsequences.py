class Code01_DistinctSubsequences:
    @staticmethod
    # 动态规划方法
    def numDistinct1(s, target):
        n = len(s)
        m = len(target)
        dp = [[0] * (m + 1) for _ in range(n + 1)]

        # 初始化，s的任何前缀形成的序列都包含空序列
        for i in range(n + 1):
            dp[i][0] = 1

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                dp[i][j] = dp[i - 1][j]  # 不使用s中的当前字符
                if s[i - 1] == target[j - 1]:
                    dp[i][j] += dp[i - 1][j - 1]  # 使用s中的当前字符

        return dp[n][m]

    @staticmethod
    # 动态规划，空间优化版
    def numDistinct2(s, target):
        n = len(s)
        m = len(target)
        dp = [0] * (m + 1)
        dp[0] = 1  # 任何字符串的子序列都包含空序列

        for i in range(1, n + 1):
            for j in range(m, 0, -1):  # 从后向前更新，避免干扰未处理的数据
                if s[i - 1] == target[j - 1]:
                    dp[j] += dp[j - 1]  # 更新dp[j]，使用当前s中的字符

        return dp[m]
