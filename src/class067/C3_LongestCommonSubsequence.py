class Solution:
    # 最长公共子序列
    # 给定两个字符串text1和text2
    # 返回这两个字符串的最长公共子序列的长度
    # 如果不存在公共子序列，返回0
    # 两个字符串的公共子序列是这两个字符串所共同拥有的子序列
    def longestCommonSubsequence1(self, str1, str2):
        s1 = list(str1)
        s2 = list(str2)
        return self.f1(s1, s2, len(s1) - 1, len(s2) - 1)

    # s1[0...i1]与s2[0...i2]最长公共子序列长度
    def f1(self, s1, s2, i1, i2):
        if i1 < 0 or i2 < 0:
            return 0
        p1 = self.f1(s1, s2, i1 - 1, i2 - 1)
        p2 = self.f1(s1, s2, i1 - 1, i2)
        p3 = self.f1(s1, s2, i1, i2 - 1)
        p4 = 1 + p1 if s1[i1] == s2[i2] else 0
        return max(p1, p2, p3, p4)

    # 为了避免很多边界讨论
    # 很多时候往往不用下标来定义尝试，而是用长度来定义尝试
    # 因为长度最短是0，而下标越界的话讨论起来就比较麻烦
    def longestCommonSubsequence2(self, str1, str2):
        s1 = list(str1)
        s2 = list(str2)
        return self.f2(s1, s2, len(s1), len(s2))

    # s1[前缀长度为len1]对应s2[前缀长度为len2]
    # 最长公共子序列长度
    def f2(self, s1, s2, len1, len2):
        if len1 == 0 or len2 == 0:
            return 0
        if s1[len1 - 1] == s2[len2 - 1]:
            return self.f2(s1, s2, len1 - 1, len2 - 1) + 1
        else:
            return max(self.f2(s1, s2, len1 - 1, len2), self.f2(s1, s2, len1, len2 - 1))

    # 记忆化搜索
    def longestCommonSubsequence3(self, str1, str2):
        s1 = list(str1)
        s2 = list(str2)
        dp = [[-1 for _ in range(len(s2) + 1)] for _ in range(len(s1) + 1)]
        return self.f3(s1, s2, len(s1), len(s2), dp)

    def f3(self, s1, s2, len1, len2, dp):
        if len1 == 0 or len2 == 0:
            return 0
        if dp[len1][len2] != -1:
            return dp[len1][len2]
        if s1[len1 - 1] == s2[len2 - 1]:
            dp[len1][len2] = self.f3(s1, s2, len1 - 1, len2 - 1, dp) + 1
        else:
            dp[len1][len2] = max(self.f3(s1, s2, len1 - 1, len2, dp), self.f3(s1, s2, len1, len2 - 1, dp))
        return dp[len1][len2]

    # 严格位置依赖的动态规划
    def longestCommonSubsequence4(self, str1, str2):
        s1 = list(str1)
        s2 = list(str2)
        dp = [[0] * (len(s2) + 1) for _ in range(len(s1) + 1)]
        for len1 in range(1, len(s1) + 1):
            for len2 in range(1, len(s2) + 1):
                if s1[len1 - 1] == s2[len2 - 1]:
                    dp[len1][len2] = dp[len1 - 1][len2 - 1] + 1
                else:
                    dp[len1][len2] = max(dp[len1 - 1][len2], dp[len1][len2 - 1])
        return dp[len(s1)][len(s2)]

    # 严格位置依赖的动态规划 + 空间压缩
    def longestCommonSubsequence5(self, str1, str2):
        s1, s2 = (str1, str2) if len(str1) >= len(str2) else (str2, str1)
        dp = [0] * (len(s2) + 1)
        for len1 in range(1, len(s1) + 1):
            leftUp = 0
            for len2 in range(1, len(s2) + 1):
                backup = dp[len2]
                if s1[len1 - 1] == s2[len2 - 1]:
                    dp[len2] = leftUp + 1
                else:
                    dp[len2] = max(dp[len2], dp[len2 - 1])
                leftUp = backup
        return dp[len(s2)]
