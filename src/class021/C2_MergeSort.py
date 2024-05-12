# 归并排序，填函数练习风格
# 测试链接 : https://leetcode.cn/problems/sort-an-array/

class Code02_MergeSort:
    MAXN = 50001
    help = [0] * MAXN

    @staticmethod
    def sortArray(nums):
        if len(nums) > 1:
            # mergeSort1为递归方法
            # mergeSort2为非递归方法
            # 用哪个都可以
            # Code02_MergeSort.mergeSort1(nums)
            Code02_MergeSort.mergeSort2(nums)
        return nums

    # 归并排序递归版
    @staticmethod
    def mergeSort1(arr):
        Code02_MergeSort.sort(arr, 0, len(arr) - 1)

    @staticmethod
    def sort(arr, l, r):
        if l == r:
            return
        m = (l + r) // 2
        Code02_MergeSort.sort(arr, l, m)
        Code02_MergeSort.sort(arr, m + 1, r)
        Code02_MergeSort.merge(arr, l, m, r)

    # 归并排序非递归版
    @staticmethod
    def mergeSort2(arr):
        n = len(arr)
        step = 1
        while step < n:
            l = 0
            while l < n:
                m = l + step - 1
                if m + 1 >= n:
                    break
                r = min(l + (step << 1) - 1, n - 1)
                Code02_MergeSort.merge(arr, l, m, r)
                l = r + 1
            step <<= 1

    @staticmethod
    def merge(arr, l, m, r):
        i = l
        a = l
        b = m + 1
        while a <= m and b <= r:
            Code02_MergeSort.help[i] = arr[a] if arr[a] <= arr[b] else arr[b]
            i += 1
            if arr[a] <= arr[b]:
                a += 1
            else:
                b += 1
        while a <= m:
            Code02_MergeSort.help[i] = arr[a]
            a += 1
            i += 1
        while b <= r:
            Code02_MergeSort.help[i] = arr[b]
            b += 1
            i += 1
        for i in range(l, r + 1):
            arr[i] = Code02_MergeSort.help[i]

if __name__ == "__main__":
    arr = [3, 8, 7, 6, 4, 5, 1, 2]
    sorted_arr = Code02_MergeSort.sortArray(arr)
    print("数组最大值 :", sorted_arr)
