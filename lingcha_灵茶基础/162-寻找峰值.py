# 峰顶：大于左右相临元素
# 红色为左侧，蓝色：右侧元素
# 初始化左指针=0，右指针7-2=5
# 二分：初始化左指针 = 0
# M在峰顶左侧
from Optional import list 
# 开区间做法, 时间复杂度O(logN)
def findPeakElement(self, nums: List[int]) -> int:
    # 峰值的范围是[0, n-2]
    # 开区间的范围就是(-1, n-1)
    # 初始化左指针，右指针=len(nums) -1 
    l = -1
    r = len(nums) - 1
    while l + 1 < r: # 区间不为空
        mid = (l + r) // 2
        if nums[mid] > nums[mid + 1] # 蓝色
            r = mid
        else: 
            l = mid
    return r

