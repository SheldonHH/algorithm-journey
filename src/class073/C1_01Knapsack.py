import sys
input = sys.stdin.read

def compute1(n, t, cost, val):
    # 严格位置依赖的动态规划
    # 使用二维数组 dp[i][j] 来存储使用前 i 个物品，容量为 j 时的最大价值
    dp = [[0] * (t + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(t + 1):
            dp[i][j] = dp[i - 1][j]  # 不选择当前物品
            if j >= cost[i]:
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + val[i])  # 选择当前物品
    return dp[n][t]

def compute2(n, t, cost, val):
    # 空间压缩技术
    # 使用一维数组 dp[j] 来存储容量为 j 的最大价值
    dp = [0] * (t + 1)
    for i in range(1, n + 1):
        for j in range(t, cost[i] - 1, -1):
            dp[j] = max(dp[j], dp[j - cost[i]] + val[i])
    return dp[t]

def main():
    data = input().split()
    index = 0
    while index < len(data):
        t = int(data[index])
        index += 1
        n = int(data[index])
        index += 1
        cost = [0] * (n + 1)
        val = [0] * (n + 1)
        for i in range(1, n + 1):
            cost[i] = int(data[index])
            index += 1
            val[i] = int(data[index])
            index += 1
        result = compute2(n, t, cost, val)
        sys.stdout.write(str(result) + '\n')

if __name__ == "__main__":
    main()
