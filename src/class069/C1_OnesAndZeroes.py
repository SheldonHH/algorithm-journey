class Code01_OnesAndZeroes:
    def __init__(self):
        self.zeros = 0
        self.ones = 0

    # 统计一个字符串中0的1的数量
    def zeros_and_ones(self, str):
        self.zeros = str.count('0')
        self.ones = str.count('1')

    # strs[i....]自由选择，希望零的数量不超过z、一的数量不超过o
    # 最多能选多少个字符串
    def f1(self, strs, i, z, o):
        if i == len(strs):
            return 0
        # 不使用当前的strs[i]字符串
        p1 = self.f1(strs, i + 1, z, o)
        # 使用当前的strs[i]字符串
        p2 = 0
        self.zeros_and_ones(strs[i])
        if self.zeros <= z and self.ones <= o:
            p2 = 1 + self.f1(strs, i + 1, z - self.zeros, o - self.ones)
        return max(p1, p2)

    def find_max_form1(self, strs, m, n):
        return self.f1(strs, 0, m, n)

    # 记忆化搜索
    def f2(self, strs, i, z, o, dp):
        if i == len(strs):
            return 0
        if dp[i][z][o] is not None:
            return dp[i][z][o]
        p1 = self.f2(strs, i + 1, z, o, dp)
        p2 = 0
        self.zeros_and_ones(strs[i])
        if self.zeros <= z and self.ones <= o:
            p2 = 1 + self.f2(strs, i + 1, z - self.zeros, o - self.ones, dp)
        ans = max(p1, p2)
        dp[i][z][o] = ans
        return ans

    def find_max_form2(self, strs, m, n):
        dp = [[None] * (n + 1) for _ in range(m + 1)]
        return self.f2(strs, 0, m, n, dp)

    # 动态规划
    def find_max_form3(self, strs, m, n):
        len_strs = len(strs)
        dp = [[[0] * (n + 1) for _ in range(m + 1)] for _ in range(len_strs + 1)]
        for i in range(len_strs - 1, -1, -1):
            self.zeros_and_ones(strs[i])
            for z in range(m + 1):
                for o in range(n + 1):
                    p1 = dp[i + 1][z][o]
                    p2 = 0
                    if self.zeros <= z and self.ones <= o:
                        p2 = 1 + dp[i + 1][z - self.zeros][o - self.ones]
                    dp[i][z][o] = max(p1, p2)
        return dp[0][m][n]

    # 优化的动态规划
    def find_max_form4(self, strs, m, n):
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for s in strs:
            self.zeros_and_ones(s)
            for z in range(m, self.zeros - 1, -1):
                for o in range(n, self.ones - 1, -1):
                    dp[z][o] = max(dp[z][o], 1 + dp[z - self.zeros][o - self.ones])
        return dp[m][n]
