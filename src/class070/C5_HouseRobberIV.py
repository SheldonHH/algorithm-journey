class Code05_HouseRobberIV:
    def min_capability(self, nums, k):
        l, r = min(nums), max(nums)
        ans = 0
        # 使用二分法确定小偷的最小窃取能力
        while l <= r:
            m = (l + r) // 2
            if self.most_rob1(nums, m) >= k:
                ans = m
                r = m - 1
            else:
                l = m + 1
        return ans

    # 盗贼能力为ability时，返回盗贼最多能窃取的房屋数量
    def most_rob1(self, nums, ability):
        n = len(nums)
        if n == 1:
            return 1 if nums[0] <= ability else 0
        if n == 2:
            return 1 if nums[0] <= ability or nums[1] <= ability else 0

        dp = [0] * n
        dp[0] = 1 if nums[0] <= ability else 0
        dp[1] = 1 if nums[0] <= ability or nums[1] <= ability else 0
        for i in range(2, n):
            dp[i] = max(dp[i-1], (1 if nums[i] <= ability else 0) + dp[i-2])
        return dp[-1]

    # 空间压缩优化版本
    def most_rob2(self, nums, ability):
        n = len(nums)
        if n == 1:
            return 1 if nums[0] <= ability else 0
        if n == 2:
            return 1 if nums[0] <= ability or nums[1] <= ability else 0

        prepre = 1 if nums[0] <= ability else 0
        pre = 1 if nums[0] <= ability or nums[1] <= ability else 0
        for i in range(2, n):
            cur = max(pre, (1 if nums[i] <= ability else 0) + prepre)
            prepre, pre = pre, cur
        return pre

    # 贪心算法优化版本
    def most_rob3(self, nums, ability):
        ans = 0
        i = 0
        n = len(nums)
        while i < n:
            if nums[i] <= ability:
                ans += 1
                i += 1  # Skip the next house
            i += 1
        return ans

# 示例使用
if __name__ == "__main__":
    solution = Code05_HouseRobberIV()
    nums = [2, 3, 2]
    k = 2
    print("Minimum capability required to rob at least", k, "houses:", solution.min_capability(nums, k))
