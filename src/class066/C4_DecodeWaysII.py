def num_decodings(s: str) -> int:
    n = len(s)
    mod = 1000000007

    # Create the dp array
    dp = [0] * (n + 1)
    dp[n] = 1

    for i in range(n - 1, -1, -1):
        if s[i] == '0':
            dp[i] = 0
        else:
            # Single character decoding
            dp[i] = (9 if s[i] == '*' else 1) * dp[i + 1]

            # Check for two-character decoding
            if i + 1 < n:
                if s[i] != '*':
                    if s[i + 1] != '*':
                        if int(s[i:i+2]) <= 26:
                            dp[i] += dp[i + 2]
                    else:
                        if s[i] == '1':
                            dp[i] += dp[i + 2] * 9
                        elif s[i] == '2':
                            dp[i] += dp[i + 2] * 6
                else:
                    if s[i + 1] != '*':
                        dp[i] += dp[i + 2] * (2 if s[i + 1] <= '6' else 1)
                    else:
                        dp[i] += dp[i + 2] * 15
        dp[i] %= mod

    return dp[0]

# Example usage:
print(num_decodings("1*"))
