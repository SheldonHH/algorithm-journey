MOD = 1000000007
MAXN = 5001

# 使用二维列表来存储动态规划的结果
dp = [[0] * MAXN for _ in range(MAXN)]

def ways2(n, m):
    # 初始化第一列，只有一种颜色的情况
    for i in range(1, n + 1):
        dp[i][1] = m
    
    # 动态规划填表
    for i in range(2, n + 1):
        for j in range(2, m + 1):
            dp[i][j] = (dp[i-1][j] * j) % MOD
            dp[i][j] = ((dp[i-1][j-1] * (m - j + 1)) + dp[i][j]) % MOD
    
    return dp[n][m]

def main():
    # 功能测试
    N = 9
    M = 9
    print("功能测试开始")
    for n in range(1, N + 1):
        for m in range(1, M + 1):
            result = ways2(n, m)
            print(f"n = {n}, m = {m}, ways = {result}")
    print("功能测试结束")

    # 性能测试
    n = 5000
    m = 4877
    print("性能测试开始")
    print(f"n = {n}, m = {m}")
    import time
    start = time.time()
    ans = ways2(n, m)
    end = time.time()
    print("取余之后的结果 :", ans)
    print("运行时间 :", (end - start) * 1000, "毫秒")
    print("性能测试结束")

if __name__ == "__main__":
    main()
