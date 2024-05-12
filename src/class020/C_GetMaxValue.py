# 用这个例子讲解递归如何执行
class GetMaxValue:

    @staticmethod
    def maxValue(arr):
        return GetMaxValue.f(arr, 0, len(arr) - 1)

    # arr[l....r]范围上的最大值
    @staticmethod
    def f(arr, l, r):
        if l == r:
            return arr[l]
        m = (l + r) // 2
        lmax = GetMaxValue.f(arr, l, m)
        rmax = GetMaxValue.f(arr, m + 1, r)
        return max(lmax, rmax)

if __name__ == "__main__":
    arr = [3, 8, 7, 6, 4, 5, 1, 2]
    print("数组最大值 :", GetMaxValue.maxValue(arr))
