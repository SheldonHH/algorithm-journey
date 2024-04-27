from typing import List
import random

def reverse(nums: List[int], l: int, r: int) -> None:
    # nums[l...r]范围上的数字进行逆序调整
    while l < r:
        nums[l], nums[r] = nums[r], nums[l]
        l += 1
        r -= 1

def max_sum(nums: List[int]) -> int:
    # 返回子数组最大累加和
    n = len(nums)
    ans = pre = nums[0]
    for i in range(1, n):
        pre = max(nums[i], pre + nums[i])
        ans = max(ans, pre)
    return ans

def max_sum_reverse1(nums: List[int]) -> int:
    # 暴力方法，为了验证
    ans = float('-inf')
    for l in range(len(nums)):
        for r in range(l, len(nums)):
            nums_copy = nums[:]
            reverse(nums_copy, l, r)
            ans = max(ans, max_sum(nums_copy))
    return ans

def max_sum_reverse2(nums: List[int]) -> int:
    # 正式方法，时间复杂度O(n)
    n = len(nums)
    start = [0] * n
    start[-1] = nums[-1]
    for i in range(n-2, -1, -1):
        start[i] = max(nums[i], nums[i] + start[i + 1])
    ans = start[0]
    end = max_end = nums[0]
    for i in range(1, n):
        ans = max(ans, max_end + start[i])
        end = max(nums[i], end + nums[i])
        max_end = max(max_end, end)
    return max(ans, max_end)

def random_array(n: int, v: int) -> List[int]:
    # 生成随机数组
    return [random.randint(-v, v) for _ in range(n)]

# 为了测试
if __name__ == "__main__":
    n = 50
    v = 200
    test_time = 20000
    print("测试开始")
    for _ in range(test_time):
        len_ = random.randint(1, n)
        arr = random_array(len_, v)
        ans1 = max_sum_reverse1(arr)
        ans2 = max_sum_reverse2(arr)
        if ans1 != ans2:
            print("出错了!")
    print("测试结束")
