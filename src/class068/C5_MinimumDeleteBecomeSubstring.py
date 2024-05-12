class Code05_MinimumDeleteBecomeSubstring:
    @staticmethod
    def min_delete1(s1, s2):
        """
        暴力方法
        为了验证
        """
        all_subsequences = []
        Code05_MinimumDeleteBecomeSubstring.generate_subsequences(s1, 0, "", all_subsequences)
        # 排序 : 长度大的子序列先考虑
        all_subsequences.sort(key=len, reverse=True)
        for sub in all_subsequences:
            if sub in s2:
                # 检查s2中，是否包含当前的s1子序列sub
                return len(s1) - len(sub)
        return len(s1)

    @staticmethod
    def generate_subsequences(s1, index, path, subsequences):
        """
        生成s1字符串的所有子序列串
        """
        if index == len(s1):
            subsequences.append(path)
        else:
            Code05_MinimumDeleteBecomeSubstring.generate_subsequences(s1, index + 1, path, subsequences)
            Code05_MinimumDeleteBecomeSubstring.generate_subsequences(s1, index + 1, path + s1[index], subsequences)

    @staticmethod
    def min_delete2(s1, s2):
        """
        正式方法，动态规划
        """
        n, m = len(s1), len(s2)
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            dp[i][0] = i
            for j in range(1, m + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = dp[i - 1][j] + 1
        return min(dp[n][j] for j in range(m + 1))

    @staticmethod
    def random_string(n, v):
        """
        为了验证
        生成长度为n，有v种字符的随机字符串
        """
        from random import choice
        return ''.join(choice('abcdefghijklmnopqrstuvwxyz'[:v]) for _ in range(n))

    @staticmethod
    def test():
        """
        对数器
        """
        n, v, test_time = 12, 3, 20000
        print("测试开始")
        from random import randint
        for _ in range(test_time):
            len1 = randint(1, n)
            len2 = randint(1, n)
            s1 = Code05_MinimumDeleteBecomeSubstring.random_string(len1, v)
            s2 = Code05_MinimumDeleteBecomeSubstring.random_string(len2, v)
            ans1 = Code05_MinimumDeleteBecomeSubstring.min_delete1(s1, s2)
            ans2 = Code05_MinimumDeleteBecomeSubstring.min_delete2(s1, s2)
            if ans1 != ans2:
                print("出错了!")
        print("测试结束")

# If you want to run the test method
if __name__ == '__main__':
    Code05_MinimumDeleteBecomeSubstring.test()
