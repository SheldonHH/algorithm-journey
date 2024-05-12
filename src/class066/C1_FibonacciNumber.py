def fib1(n):
    def f1(i):
        if i == 0:
            return 0
        if i == 1:
            return 1
        return f1(i - 1) + f1(i - 2)

    return f1(n)

def fib2(n):
    dp = [-1] * (n + 1)

    def f2(i):
        if i == 0:
            return 0
        if i == 1:
            return 1
        if dp[i] != -1:
            return dp[i]
        dp[i] = f2(i - 1) + f2(i - 2)
        return dp[i]

    return f2(n)

def fib3(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    dp = [0] * (n + 1)
    dp[1] = 1
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    return dp[n]

def fib4(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    last_last, last = 0, 1
    for i in range(2, n + 1):
        cur = last_last + last
        last_last = last
        last = cur
    return last
