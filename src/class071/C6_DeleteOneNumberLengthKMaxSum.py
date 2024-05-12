def max_sum1(nums, k):
    n = len(nums)
    if n <= k:
        return 0
    ans = float('-inf')
    for i in range(n):
        rest = nums[:i] + nums[i+1:]
        ans = max(ans, len_k_max_sum(rest, k))
    return ans

def len_k_max_sum(nums, k):
    n = len(nums)
    ans = float('-inf')
    for i in range(n - k + 1):
        cur = sum(nums[i:i+k])
        ans = max(ans, cur)
    return ans

def max_sum2(nums, k):
    n = len(nums)
    if n <= k:
        return 0
    window = []
    sum = 0
    ans = float('-inf')
    for i in range(n):
        while window and nums[window[-1]] >= nums[i]:
            window.pop()
        window.append(i)
        sum += nums[i]
        if i >= k:
            ans = max(ans, sum - nums[window[0]])
            if window[0] == i - k:
                window.pop(0)
            sum -= nums[i - k]
    return ans

def random_array(n, v):
    from random import randint
    return [randint(-v, v) for _ in range(n)]

def test():
    n = 200
    v = 1000
    test_times = 10000
    print("测试开始")
    for _ in range(test_times):
        len = randint(1, n)
        nums = random_array(len, v)
        k = randint(1, n)
        ans1 = max_sum1(nums, k)
        ans2 = max_sum2(nums, k)
        if ans1 != ans2:
            print("出错了!")
            return
    print("测试结束")

if __name__ == "__main__":
    test()
