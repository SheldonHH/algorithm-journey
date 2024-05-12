def mincost_tickets1(days, costs):
    # 递归方式求解最小票价
    def f1(i):
        # 如果已经没有旅行日，返回 0
        if i == len(days):
            return 0
        # 初始化最小成本为无穷大
        ans = float('inf')
        # 遍历所有购票方案
        for k in range(3):
            j = i
            # 找到当前票种可以覆盖的最后一天
            while j < len(days) and days[i] + durations[k] > days[j]:
                j += 1
            # 更新最小成本
            ans = min(ans, costs[k] + f1(j))
        return ans

    # 三种票的有效期限
    durations = [1, 7, 30]
    # 开始递归求解
    return f1(0)


def mincost_tickets2(days, costs):
    # 使用记忆化搜索的递归方式
    dp = [float('inf')] * len(days)

    def f2(i):
        # 如果已经没有旅行日，返回 0
        if i == len(days):
            return 0
        # 如果这一天已经计算过，直接返回结果
        if dp[i] != float('inf'):
            return dp[i]
        # 初始化最小成本为无穷大
        ans = float('inf')
        # 遍历所有购票方案
        for k in range(3):
            j = i
            # 找到当前票种可以覆盖的最后一天
            while j < len(days) and days[i] + durations[k] > days[j]:
                j += 1
            # 更新最小成本
            ans = min(ans, costs[k] + f2(j))
        # 记录这一天的最小成本结果
        dp[i] = ans
        return ans

    # 三种票的有效期限
    durations = [1, 7, 30]
    # 开始记忆化搜索
    return f2(0)


def mincost_tickets3(days, costs):
    # 使用动态规划自底向上方法求解
    n = len(days)
    dp = [float('inf')] * (n + 1)
    # 初始化最后一天的成本为 0
    dp[n] = 0
    # 三种票的有效期限
    durations = [1, 7, 30]
    # 从后向前计算每一天的最小票价
    for i in range(n - 1, -1, -1):
        # 遍历所有购票方案
        for k in range(3):
            j = i
            # 找到当前票种可以覆盖的最后一天
            while j < len(days) and days[i] + durations[k] > days[j]:
                j += 1
            # 更新最小成本
            dp[i] = min(dp[i], costs[k] + dp[j])
    # 返回第一天的最小票价
    return dp[0]


# 示例使用
days = [1, 4, 6, 7, 8, 20]
costs = [2, 7, 15]
print(mincost_tickets1(days, costs))  # 使用递归方法
print(mincost_tickets2(days, costs))  # 使用记忆化递归
print(mincost_tickets3(days, costs))  # 使用动态规划
