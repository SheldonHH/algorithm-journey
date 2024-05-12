def max_envelopes(envelopes):
    # 俄罗斯套娃信封问题
    # 给你一个二维整数数组envelopes ，其中envelopes[i]=[wi, hi]
    # 表示第 i 个信封的宽度和高度
    # 当另一个信封的宽度和高度都比这个信封大的时候
    # 这个信封就可以放进另一个信封里，如同俄罗斯套娃一样
    # 请计算 最多能有多少个信封能组成一组“俄罗斯套娃”信封
    # 即可以把一个信封放到另一个信封里面，注意不允许旋转信封
    n = len(envelopes)
    # 排序策略:
    # 宽度从小到大
    # 宽度一样，高度从大到小
    envelopes.sort(key=lambda x: (x[0], -x[1]))
    ends = [0] * n
    len = 0
    for i in range(n):
        num = envelopes[i][1]
        find = binary_search(ends, len, num)
        if find == -1:
            ends[len] = num
            len += 1
        else:
            ends[find] = num
    return len

def binary_search(ends, length, num):
    l, r = 0, length - 1
    ans = -1
    while l <= r:
        m = (l + r) // 2
        if ends[m] >= num:
            ans = m
            r = m - 1
        else:
            l = m + 1
    return ans

# Example usage:
envelopes = [[5,4],[6,4],[6,7],[2,3]]
print(max_envelopes(envelopes))
