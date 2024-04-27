class Code01_MaximumSubarray:
    def max_sub_array1(self, nums):
        n = len(nums)
        # dp[i] : 子数组必须以i位置的数做结尾，往左能延伸出来的最大累加和
        dp = [0] * n
        dp[0] = nums[0]
        ans = nums[0]
        for i in range(1, n):
            dp[i] = max(nums[i], dp[i - 1] + nums[i])
            ans = max(ans, dp[i])
        return ans

    def max_sub_array2(self, nums):
        n = len(nums)
        ans = nums[0]
        pre = nums[0]
        for i in range(1, n):
            # 空间压缩后的DP计算，只保留上一个状态的最大值
            pre = max(nums[i], pre + nums[i])
            ans = max(ans, pre)
        return ans

    def extra(self, nums):
        sum = float('-inf')
        left = right = 0
        pre = float('-inf')
        l = 0
        # 找到拥有最大累加和的子数组
        for r in range(len(nums)):
            if pre >= 0:
                pre += nums[r]
            else:
                pre = nums[r]
                l = r
            if pre > sum:
                sum = pre
                left = l
                right = r
        # 更新好全局变量left、right、sum
        return left, right, sum

# 示例使用
if __name__ == "__main__":
    solution = Code01_MaximumSubarray()
    nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    print("Max Subarray Sum (DP):", solution.max_sub_array1(nums))
    print("Max Subarray Sum (Optimized):", solution.max_sub_array2(nums))

    left, right, sum = solution.extra(nums)
    print("Max Subarray (Extra): Sum =", sum, ", Left =", left, ", Right =", right)
