# 1. Python 版本：递归暴力尝试（未优化）
def num_decodings1(s: str) -> int:
    # 递归暴力尝试解码方法
    def dfs(i: int) -> int:
        if i == len(s):
            return 1  # 字符串结束，有效解码
        if s[i] == '0':
            return 0  # 当前字符是'0'，无法解码
        ans = dfs(i + 1) * (9 if s[i] == '*' else 1)  # 单个字符解码
        if i + 1 < len(s):  # 双字符组合解码
            if s[i] != '*':
                if s[i + 1] != '*':
                    if int(s[i:i+2]) <= 26:
                        ans += dfs(i + 2)
                else:
                    if s[i] == '1':
                        ans += dfs(i + 2) * 9
                    elif s[i] == '2':
                        ans += dfs(i + 2) * 6
            else:
                if s[i + 1] != '*':
                    if s[i + 1] <= '6':
                        ans += dfs(i + 2) * 2
                    else:
                        ans += dfs(i + 2)
                else:
                    ans += dfs(i + 2) * 15
        return ans
    return dfs(0)

# 测试
print(num_decodings1("1*"))


# 2. Python 版本：递归暴力尝试（带备忘录）
def num_decodings2(s: str) -> int:
    MOD = 1000000007
    dp = [-1] * len(s)  # 备忘录

    def dfs(i: int) -> int:
        if i == len(s):
            return 1
        if s[i] == '0':
            return 0
        if dp[i] != -1:
            return dp[i]
        ans = dfs(i + 1) * (9 if s[i] == '*' else 1) % MOD
        if i + 1 < len(s):
            if s[i] != '*':
                if s[i + 1] != '*':
                    if int(s[i:i+2]) <= 26:
                        ans = (ans + dfs(i + 2)) % MOD
                else:
                    if s[i] == '1':
                        ans = (ans + dfs(i + 2) * 9) % MOD
                    elif s[i] == '2':
                        ans = (ans + dfs(i + 2) * 6) % MOD
            else:
                if s[i + 1] != '*':
                    ans = (ans + dfs(i + 2) * (2 if s[i + 1] <= '6' else 1)) % MOD
                else:
                    ans = (ans + dfs(i + 2) * 15) % MOD
        dp[i] = ans
        return ans

    return dfs(0)

# 测试
print(num_decodings2("1*"))


# 3. Python 版本：动态规划
def num_decodings3(s: str) -> int:
    MOD = 1000000007
    n = len(s)
    dp = [0] * (n + 1)
    dp[n] = 1  # 空字符串解码方式为1

    for i in range(n - 1, -1, -1):
        if s[i] == '0':
            dp[i] = 0
        else:
            dp[i] = dp[i + 1] * (9 if s[i] == '*' else 1) % MOD
            if i + 1 < n:
                if s[i] != '*':
                    if s[i + 1] != '*':
                        if int(s[i:i+2]) <= 26:
                            dp[i] = (dp[i] + dp[i + 2]) % MOD
                    else:
                        if s[i] == '1':
                            dp[i] = (dp[i] + dp[i + 2] * 9) % MOD
                        elif s[i] == '2':
                            dp[i] = (dp[i] + dp[i + 2] * 6) % MOD
                else:
                    if s[i + 1] != '*':
                        dp[i] = (dp[i] + dp[i + 2] * (2 if s[i + 1] <= '6' else 1)) % MOD
                    else:
                        dp[i] = (dp[i] + dp[i + 2] * 15) % MOD

    return dp[0]

# 测试
print(num_decodings3("1*"))


# 4. Python 版本：优化动态规划（空间优化）
def num_decodings4(s: str) -> int:
    MOD = 1000000007
    n = len(s)
    cur = 0
    next = 1
    nextNext = 0

    for i in range(n - 1, -1, -1):
        if s[i] == '0':
            cur = 0
        else:
            cur = next * (9 if s[i] == '*' else 1) % MOD
            if i + 1 < n:
                if s[i] != '*':
                    if s[i + 1] != '*':
                        if int(s[i:i+2]) <= 26:
                            cur = (cur + nextNext) % MOD
                    else:
                        if s[i] == '1':
                            cur = (cur + nextNext * 9) % MOD
                        elif s[i] == '2':
                            cur = (cur + nextNext * 6) % MOD
                else:
                    if s[i + 1] != '*':
                        cur = (cur + nextNext * (2 if s[i + 1] <= '6' else 1)) % MOD
                    else:
                        cur = (cur + nextNext * 15) % MOD
        nextNext = next
        next = cur

    return next

# 测试
print(num_decodings4("1*"))
