def find_target_sum_ways1(nums, target):
    # 普通尝试，暴力递归版
    def f1(i, sum):
        if i == len(nums):
            return 1 if sum == target else 0
        return f1(i + 1, sum + nums[i]) + f1(i + 1, sum - nums[i])

    return f1(0, 0)

def find_target_sum_ways2(nums, target):
    # 普通尝试，记忆化搜索版
    dp = {}
    
    def f2(i, current_sum):
        if i == len(nums):
            return 1 if current_sum == target else 0
        if (i, current_sum) in dp:
            return dp[(i, current_sum)]
        
        dp[(i, current_sum)] = (f2(i + 1, current_sum + nums[i]) +
                                f2(i + 1, current_sum - nums[i]))
        return dp[(i, current_sum)]

    return f2(0, 0)

def find_target_sum_ways3(nums, target):
    # 新思路，转化为01背包问题
    total_sum = sum(nums)
    if total_sum < target or (target + total_sum) % 2 != 0:
        return 0
    s = (total_sum + target) // 2
    dp = [0] * (s + 1)
    dp[0] = 1  # base case

    for num in nums:
        for j in range(s, num - 1, -1):
            dp[j] += dp[j - num]
    
    return dp[s]

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    target = int(data[1])
    nums = list(map(int, data[2:2+n]))
    
    print(find_target_sum_ways3(nums, target))

if __name__ == "__main__":
    main()
