class Code03_InterleavingString:
    # 交错字符串
    # 给定三个字符串 s1、s2、s3
    # 请帮忙验证s3是否由s1和s2交错组成
    @staticmethod
    def is_interleave1(s1, s2, s3):
        if len(s1) + len(s2) != len(s3):
            return False
        n, m = len(s1), len(s2)
        dp = [[False] * (m + 1) for _ in range(n + 1)]
        dp[0][0] = True
        
        for i in range(1, n + 1):
            if s1[i - 1] != s3[i - 1]:
                break
            dp[i][0] = True
        
        for j in range(1, m + 1):
            if s2[j - 1] != s3[j - 1]:
                break
            dp[0][j] = True
        
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                dp[i][j] = (s1[i - 1] == s3[i + j - 1] and dp[i - 1][j]) or (s2[j - 1] == s3[i + j - 1] and dp[i][j - 1])
        
        return dp[n][m]

    # 空间压缩
    @staticmethod
    def is_interleave2(s1, s2, s3):
        if len(s1) + len(s2) != len(s3):
            return False
        n, m = len(s1), len(s2)
        dp = [False] * (m + 1)
        dp[0] = True
        
        for j in range(1, m + 1):
            if s2[j - 1] != s3[j - 1]:
                break
            dp[j] = True
        
        for i in range(1, n + 1):
            dp[0] = s1[i - 1] == s3[i - 1] and dp[0]
            for j in range(1, m + 1):
                dp[j] = (s1[i - 1] == s3[i + j - 1] and dp[j]) or (s2[j - 1] == s3[i + j - 1] and dp[j - 1])
        
        return dp[m]
