# target = 7
# nums = [2,3,1,2,4,3]

# 暴力时间复杂度O(n^2)
# 暴力做法：都是整数的特点，单调性
# 
# 方法2: 不断向右缩短左端点
# O(n)
def minSubArrayLen(target: int , nums: List[int]):
    n = len(nums)
    ans = n + 1 # inf 方便后面
    s = l = 0
    # 枚举子数组右端点
    for r, x in enumerate(nums): # x: nums[right]
        # 需要把3加入s里面
        s += x
        while s - nums[l] >= target: # 此时(子数组的和 - 左端点)还是大于target，就可以放心的把左端点移出
            s -= nums[l]
            l += 1
        if s >= target:
            ans = min(ans, r - l + 1) # 特例决定➕1：r,l指向同一个元素，长度为1
        return ans if ans <= n else 0
    # ans <= n ? ans :0 

    # 为啥不判断l,r大小关系
    # 若 l == r: s - nums[l]  
    # target是正整数，0无法大于等于正整数
    # 枚举子数组右端点的一个好处



def minSubArrayLen(target: int , nums: List[int]):
    n = len(nums)
    ans = n + 1 # inf 方便后面
    s = l = 0
    # 枚举子数组右端点
    for r, x in enumerate(nums): # x: nums[right]
        # 需要把3加入s里面
        s += x
        while s>=target:
            ans = min(ans, r - l + 1)
            s -= nums[l]
            l += 1
        return ans if ans <= n else 0