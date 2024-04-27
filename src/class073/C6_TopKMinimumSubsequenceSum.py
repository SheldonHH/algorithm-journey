from heapq import heappush, heappop
import random

def top_k_sum1(nums, k):
    # 暴力方法
    all_subsequences = []
    def f1(index, sum):
        if index == len(nums):
            all_subsequences.append(sum)
        else:
            f1(index + 1, sum)
            f1(index + 1, sum + nums[index])

    f1(0, 0)
    all_subsequences.sort()
    return all_subsequences[:k]

def top_k_sum3(nums, k):
    # 正式方法
    # 用堆来做是最优解，时间复杂度O(n * log n) + O(k * log k)
    sorted_nums = sorted(nums)
    heap = []
    heappush(heap, (sorted_nums[0], 0))  # (sum, index)
    ans = [0] * k
    ans[0] = 0  # Include the empty subsequence
    for i in range(1, k):
        sum, idx = heappop(heap)
        ans[i] = sum
        if idx + 1 < len(sorted_nums):
            heappush(heap, (sum - sorted_nums[idx] + sorted_nums[idx + 1], idx + 1))
            heappush(heap, (sum + sorted_nums[idx + 1], idx + 1))
    return ans

def random_array(len, value):
    return [random.randint(0, value) for _ in range(len)]

def equals(ans1, ans2):
    return len(ans1) == len(ans2) and all(a == b for a, b in zip(ans1, ans2))

if __name__ == "__main__":
    n = 15
    v = 40
    test_time = 5000
    print("测试开始")
    for _ in range(test_time):
        len = random.randint(1, n)
        nums = random_array(len, v)
        k = random.randint(1, (1 << len) - 1)
        ans1 = top_k_sum1(nums, k)
        ans3 = top_k_sum3(nums, k)
        if not equals(ans1, ans3):
            print("出错了！")
            break
    print("测试结束")
