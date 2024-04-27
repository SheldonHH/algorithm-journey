class Code04_HouseRobberII:
    @staticmethod
    def rob(nums):
        n = len(nums)
        if n == 1:
            return nums[0]
        # 分别计算不包含第一个元素和包含第一个但不包含最后一个元素的情况
        return max(Code04_HouseRobberII.best(nums, 1, n - 1), nums[0] + Code04_HouseRobberII.best(nums, 2, n - 2))

    # nums[l....r]范围上，没有环形的概念
    # 返回：可以随意选择数字，但不能选择相邻数字的情况下，最大累加和
    @staticmethod
    def best(nums, l, r):
        if l > r:
            return 0
        if l == r:
            return nums[l]
        if l + 1 == r:
            return max(nums[l], nums[r])
        prepre = nums[l]
        pre = max(nums[l], nums[l + 1])
        for i in range(l + 2, r + 1):
            cur = max(pre, nums[i] + max(0, prepre))
            prepre = pre
            pre = cur
        return pre
