from typing import List
import random

def max_sum1(nums: List[int]) -> int:
    # 暴力方法，用于测试
    p1 = sum(nums)
    n = len(nums)
    p2 = must_one_scroll(nums, 0, n - 1)
    p3 = float('-inf')
    for i in range(1, n):
        p3 = max(p3, must_one_scroll(nums, 0, i - 1) + must_one_scroll(nums, i, n - 1))
    return max(p1, max(p2, p3))

def must_one_scroll(nums: List[int], l: int, r: int) -> int:
    # nums[l...r]范围上一定要用一次卷轴情况下的最大累加和
    ans = float('-inf')
    for a in range(l, r + 1):
        for b in range(a, r + 1):
            cur_ans = sum(nums[l:a]) + sum(nums[b+1:r+1])
            ans = max(ans, cur_ans)
    return ans

def max_sum2(nums: List[int]) -> int:
    # 正式方法，时间复杂度O(n)
    n = len(nums)
    if n == 0:
        return 0
    p1 = sum(nums)
    prefix = [0] * n
    suffix = [0] * n
    sum = nums[0]
    max_presum = max(0, nums[0])
    prefix[0] = sum
    for i in range(1, n):
        sum += nums[i]
        max_presum = max(max_presum, sum)
        prefix[i] = max(prefix[i-1], max_presum)
    sum = nums[-1]
    max_presum = max(0, sum)
    suffix[-1] = sum
    for i in range(n - 2, -1, -1):
        sum += nums[i]
        max_presum = max(max_presum, sum)
        suffix[i] = max(suffix[i + 1], max_presum)
    p2 = prefix[-1]
    p3 = float('-inf')
    for i in range(1, n):
        p3 = max(p3, prefix[i-1] + suffix[i])
    return max(p1, max(p2, p3))

def random_array(n: int, v: int) -> List[int]:
    return [random.randint(-v, v) for _ in range(n)]

# 为了测试
if __name__ == "__main__":
    n = 50
    v = 100
    test_time = 10000
    print("测试开始")
    for _ in range(test_time):
        len_ = random.randint(0, n)
        nums = random_array(len_, v)
        ans1 = max_sum1(nums)
        ans2 = max_sum2(nums)
        if ans1 != ans2:
            print("出错了!")
    print("测试结束")
