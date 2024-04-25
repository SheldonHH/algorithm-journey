def num_decodings1(s):
    # Recursive approach
    def f1(i):
        if i == len(s):
            return 1
        if s[i] == '0':
            return 0
        ans = f1(i + 1)
        if i + 1 < len(s) and int(s[i:i+2]) <= 26:
            ans += f1(i + 2)
        return ans

    return f1(0)

def num_decodings2(s):
    # Recursive with memoization
    dp = [-1] * len(s)

    def f2(i):
        if i == len(s):
            return 1
        if dp[i] != -1:
            return dp[i]
        if s[i] == '0':
            ans = 0
        else:
            ans = f2(i + 1)
            if i + 1 < len(s) and int(s[i:i+2]) <= 26:
                ans += f2(i + 2)
        dp[i] = ans
        return ans

    return f2(0)

def num_decodings3(s):
    # Dynamic programming approach
    n = len(s)
    dp = [0] * (n + 1)
    dp[n] = 1
    for i in range(n - 1, -1, -1):
        if s[i] == '0':
            dp[i] = 0
        else:
            dp[i] = dp[i + 1]
            if i + 1 < n and int(s[i:i+2]) <= 26:
                dp[i] += dp[i + 2]
    return dp[0]

def num_decodings4(s):
    # Dynamic programming with space optimization
    next = 1  # This is dp[i+1]
    next_next = 0  # This is dp[i+2]
    for i in range(len(s) - 1, -1, -1):
        if s[i] == '0':
            cur = 0
        else:
            cur = next
            if i + 1 < len(s) and int(s[i:i+2]) <= 26:
                cur += next_next
        next_next = next
        next = cur
    return next

# Example usage
s = "11106"
print(num_decodings1(s))  # Recursive
print(num_decodings2(s))  # Recursive with memoization
print(num_decodings3(s))  # Dynamic programming
print(num_decodings4(s))  # Space optimized dynamic programming
