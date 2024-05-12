def max_sum_of_three_subarrays(nums, k):
    n = len(nums)
    # sums[i] : 以i开头并且长度为k的子数组的累加和
    sums = [0] * n
    l, r, sum = 0, 0, 0
    while r < n:
        sum += nums[r]
        if r - l + 1 == k:
            sums[l] = sum
            sum -= nums[l]
            l += 1
        r += 1

    # prefix[i] :
    # 0~i范围上所有长度为k的子数组中，拥有最大累加和的子数组，是以什么位置开头的
    prefix = [0] * n
    for l in range(1, n):
        if l + k - 1 < n:
            prefix[l + k - 1] = l if sums[l] > sums[prefix[l + k - 2]] else prefix[l + k - 2]

    # suffix[i] :
    # i~n-1范围上所有长度为k的子数组中，拥有最大累加和的子数组，是以什么位置开头的
    suffix = [0] * n
    suffix[n - k] = n - k
    for l in range(n - k - 1, -1, -1):
        suffix[l] = l if sums[l] >= sums[suffix[l + 1]] else suffix[l + 1]

    # 0...i-1    i...j    j+1...n-1
    #   左     中(长度为k)     右
    max_sum = 0
    result = [0, 0, 0]
    for i in range(k, n - 2 * k + 1):
        j = i + k - 1
        p = prefix[i - 1]
        s = suffix[j + 1]
        current_sum = sums[p] + sums[i] + sums[s]
        if current_sum > max_sum:
            max_sum = current_sum
            result = [p, i, s]

    return result

# Example usage
nums = [1, 2, 1, 2, 6, 7, 5, 1]
k = 2
print(max_sum_of_three_subarrays(nums, k))
