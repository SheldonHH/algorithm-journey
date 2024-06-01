# 方法1： 前后缀
def trap(self, height: List[int]) -> int:
    # 三个O(n)相加
    # 空间复杂度也是O()
    n = len(height)
    pre_max = suf_max = [0] * n # 计算前缀最大值
    pre_max[0] = height[0]
    for i in range(1, n):
        pre_max[i] = max(pre_max[i - 1], height[i])

    suf_max[-1] = height[-1]
    for i in range(n - 2, -1, -1): # 从n-2枚举到0
        suf_max[i] = max(suf_max[i+1], height[i])
    ans = 0
    # 同时便利着三个
    for h, p, s in zip(height, pre_max, suf_max):
        ans += min(p, s) - h # 左右的最小高度 - 高度就是容量
    return ans 





# 方法2: 双向双指针
# 已经算出一部分前缀最大值和后缀最大值
# 如果前缀最大值，比后缀最大值小，那么左边木桶的容量就是前缀最大值，算完之后左指针向右扩展
#                               右                              右指针向左扩展
# L=0, R=N-1
# 好处在于无需创建额外数字
def trap(self, height: List[int]) -> int:
    n = len(height)
    ans = l = 0
    r = n - 1
    pmax = smax = 0
    while l <= r:
        pmax = max(pmax, height[l])
        smax = max(smax, height[r])
        if pmax < smax:
            ans += pmax - height[l]
            l += 1
        else:
            ans += smax - height[r]
            r -= 1
    return ans