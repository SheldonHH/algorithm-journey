# l-1永远指向小于等于8的部分
# r+1永远指向大于等于8的部分
def lower_bound(nums, target) -> int: # 闭区间 (-1,n)
    l = 0
    r = len(nums) -1 
    while l <= r:  # 非空
      # m = l + (r - l) //2
        m = (l + r) // 2
        if nums[m] < target:
            # [m + 1, right]
            l = m + 1
        else:
            r = m - 1 # [l, m - 1]
    return l # 🌟🌟 因为是r+1是，而刚好r+1就是l lower_bound

# 除了这种写法，还可以把左端点和右端点当成是开区间
# 初始化R指向n
# l == r 的时候，左闭右开区间就是空的，此时L和R都是指向答案的

# 右端点作为开区间
def lower_bound2(nums, target) -> int: # 左闭右开区间 (-1,n]   # (l, R]
    l = 0
    r = len(nums) # 指向n
    while l < r:  # 区间非空
      # m = l + (r - l) //2
        m = (l + r) // 2
        if nums[m] < target:
            # [m + 1, right)
            l = m + 1
        else:
            # [l, m)
            r = m  
    return l # r # 


# 还可以把区间的左右端点改成开区间
def lower_bound3(nums, target) -> int: # 开区间 [-1,n]
    l = -1
    r = len(nums) 
    while l + 1 < r:  # 区间非空
      # m = l + (r - l) //2
        m = (l + r) // 2
        if nums[m] < target:
            # [m + 1, right)
            l = m
        else:
            # [l, m)
            r = m  
    return l # r # 





