def find_longest_chain(pairs):
    # 最长数对链
    # 给你一个由n个数对组成的数对数组pairs
    # 其中 pairs[i] = [lefti, righti] 且 lefti < righti
    # 现在，我们定义一种 跟随 关系，当且仅当 b < c 时
    # 数对 p2 = [c, d] 才可以跟在 p1 = [a, b] 后面
    # 我们用这种形式来构造 数对链
    # 找出并返回能够形成的最长数对链的长度
    pairs.sort(key=lambda x: x[0])  # 数对根据开始位置排序，从小到大
    ends = []
    len = 0
    for left, right in pairs:
        find = binary_search(ends, len, left)
        if find == -1:
            ends.append(right)
            len += 1
        else:
            ends[find] = min(ends[find], right)
    return len

def binary_search(ends, len, num):
    # >= num最左位置
    l, r = 0, len - 1
    ans = -1
    while l <= r:
        m = (l + r) // 2
        if ends[m] >= num:
            ans = m
            r = m - 1
        else:
            l = m + 1
    return ans

def find_longest_chain2(pairs):
    # 最优解利用贪心
    pairs.sort(key=lambda x: x[1])  # 数对根据结束位置排序，从小到大
    pre = float('-inf')
    ans = 0
    for left, right in pairs:
        if pre < left:
            pre = right
            ans += 1
    return ans

# Example usage
pairs = [[1, 2], [2, 3], [3, 4]]
print(find_longest_chain(pairs))  # Using the first method
print(find_longest_chain2(pairs))  # Using the greedy method
