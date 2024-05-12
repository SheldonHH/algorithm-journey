from typing import List
from random import randint

# 修改后的暴力解法
def brute_force(nums: List[int], x: int) -> int:
    total = sum(nums)
    target = total - x
    
    if target < 0:
        return -1
    
    if target == 0:
        return len(nums)
    
    # 初始化哈希表和前缀和
    prefix_sum = 0
    prefix_sum_to_index = {0: -1}
    
    # 初始化结果
    min_len = float('inf')
    
    for i, num in enumerate(nums):
        prefix_sum += num
        
        # 更新哈希表
        if prefix_sum not in prefix_sum_to_index:
            prefix_sum_to_index[prefix_sum] = i
        
        # 查找是否有子数组的和等于 target
        if prefix_sum - target in prefix_sum_to_index:
            min_len = min(min_len, i - prefix_sum_to_index[prefix_sum - target])
    
    return len(nums) - min_len if min_len != float('inf') else -1

# 优化解法（滑动窗口）
def minOperations(nums: List[int], x: int) -> int:
    t = sum(nums) - x
    cs = 0  # 初始化 cs
    mxw = -1
    l = 0
    for r in range(len(nums)):
        cs += nums[r]
        while l <= r and cs > t:
            cs -= nums[l]
            l += 1
        if cs == t:
            mxw = max(mxw, r - l + 1)
    return -1 if mxw == -1 else len(nums) - mxw

# 对数器
def test():
    for _ in range(1000):
        n = randint(1, 10)
        nums = [randint(1, 100) for _ in range(n)]
        x = randint(1, sum(nums))
        assert minOperations(nums, x) == brute_force(nums, x), f"Failed on test {nums}, {x}"
        
    print("All tests passed.")

test()

# nums1 = [1,1,4,2,3]
# x1 = 5
# assert minOperations(nums1, x1) == brute_force(nums1, x1) == 2

# # Test Case 2
# nums2 = [5,6,7,8,9]
# x2 = 4
# assert minOperations(nums2, x2) == brute_force(nums2, x2) == -1

# # Test Case 3
# nums3 = [3,2,20,1,1,3]
# x3 = 10
# assert minOperations(nums3, x3) == brute_force(nums3, x3) == 5

# # Test Case 4
# nums4 = [86, 6, 89, 51, 39, 20, 43, 71]
# x4 = 244
# assert minOperations(nums4, x4) == brute_force(nums4, x4) == 4  # This is the one you provided.

# # Test Case 5
# nums5 = [1, 2, 3, 4, 5]
# x5 = 15
# assert minOperations(nums5, x5) == brute_force(nums5, x5) == 5  # Requires removing all elements

# print("All tests passed.")