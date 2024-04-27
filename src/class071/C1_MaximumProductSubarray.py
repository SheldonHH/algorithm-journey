from typing import List

def max_product(nums: List[int]) -> int:
    # 给定一个整数数组 nums
    # 请找出数组中乘积最大的非空连续子数组
    # 并返回该子数组所对应的乘积
    if not nums:
        return 0
    
    ans = nums[0]
    min_product = nums[0]
    max_product = nums[0]
    
    for i in range(1, len(nums)):
        # 当前的最小和最大值需要临时保存，因为计算过程中会相互影响
        cur_min = min(nums[i], min(min_product * nums[i], max_product * nums[i]))
        cur_max = max(nums[i], max(min_product * nums[i], max_product * nums[i]))
        min_product = cur_min
        max_product = cur_max
        ans = max(ans, max_product)
    
    return ans

# 示例用法
nums = [2, 3, -2, 4]
print("数组中乘积最大的非空连续子数组的乘积为:", max_product(nums))
