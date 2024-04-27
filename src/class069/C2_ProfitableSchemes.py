class Code02_ProfitableSchemes:
    mod = 1000000007

    # n : 员工的额度，不能超
    # p : 利润的额度，不能少
    # group[i] : i号项目需要几个人
    # profit[i] : i号项目产生的利润
    # 返回能做到员工不能超过n，利润不能少于p的计划有多少个
    @staticmethod
    def profitableSchemes1(n, minProfit, group, profit):
        return Code02_ProfitableSchemes.f1(group, profit, 0, n, minProfit)

    # i : 来到i号工作
    # r : 员工额度还有r人，如果r<=0说明已经没法再选择工作了
    # s : 利润还有s才能达标，如果s<=0说明之前的选择已经让利润达标了
    # 返回 : i.... r、s，有多少种方案
    @staticmethod
    def f1(g, p, i, r, s):
        if r <= 0:
            return 1 if s <= 0 else 0
        if i == len(g):
            return 1 if s <= 0 else 0
        p1 = Code02_ProfitableSchemes.f1(g, p, i + 1, r, s)
        p2 = 0
        if g[i] <= r:
            p2 = Code02_ProfitableSchemes.f1(g, p, i + 1, r - g[i], s - p[i])
        return (p1 + p2) % Code02_ProfitableSchemes.mod

    # 使用记忆化搜索优化
    @staticmethod
    def profitableSchemes2(n, minProfit, group, profit):
        dp = [[[-1 for _ in range(minProfit + 1)] for _ in range(n + 1)] for _ in range(len(group))]
        return Code02_ProfitableSchemes.f2(group, profit, 0, n, minProfit, dp)

    @staticmethod
    def f2(g, p, i, r, s, dp):
        if r <= 0:
            return 1 if s == 0 else 0
        if i == len(g):
            return 1 if s == 0 else 0
        if dp[i][r][s] != -1:
            return dp[i][r][s]
        p1 = Code02_ProfitableSchemes.f2(g, p, i + 1, r, s, dp)
        p2 = 0
        if g[i] <= r:
            p2 = Code02_ProfitableSchemes.f2(g, p, i + 1, r - g[i], max(0, s - p[i]), dp)
        ans = (p1 + p2) % Code02_ProfitableSchemes.mod
        dp[i][r][s] = ans
        return ans

    # 动态规划方法
    @staticmethod
    def profitableSchemes3(n, minProfit, group, profit):
        dp = [[0 for _ in range(minProfit + 1)] for _ in range(n + 1)]
        for r in range(n + 1):
            dp[r][0] = 1
        for i in reversed(range(len(group))):
            for r in reversed(range(n + 1)):
                for s in reversed(range(minProfit + 1)):
                    p1 = dp[r][s]
                    p2 = dp[r - group[i]][max(0, s - profit[i])] if group[i] <= r else 0
                    dp[r][s] = (p1 + p2) % Code02_ProfitableSchemes.mod
        return dp[n][minProfit]
