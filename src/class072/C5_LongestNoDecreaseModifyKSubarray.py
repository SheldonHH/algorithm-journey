import sys
import bisect

input = sys.stdin.read
def compute(arr, k):
    n = len(arr)
    if k >= n:
        return n
    
    # 生成辅助数组 right
    # right[j]: 一定以 arr[j] 做开头的情况下，arr[j...] 上最长不下降子序列长度是多少
    ends = []
    right = [0] * n
    for i in range(n-1, -1, -1):
        pos = bisect.bisect_left(ends, arr[i])
        if pos == len(ends):
            ends.append(arr[i])
        else:
            ends[pos] = arr[i]
        right[i] = pos + 1

    # 主逻辑部分
    ans = 0
    ends = []
    for i in range(k, n):
        if i - k >= 0:
            pos = bisect.bisect_left(ends, arr[i-k])
            if pos == len(ends):
                ends.append(arr[i-k])
            else:
                ends[pos] = arr[i-k]
        # 考虑修改 arr[i-k+1] 到 arr[i] 这个区间，与 right[i+1] 结合
        len_with_k = k + (right[i+1] if i + 1 < n else 0)
        pos = bisect.bisect_left(ends, arr[i+1] if i + 1 < n else float('inf'))
        len_without_k = pos + 1
        ans = max(ans, len_with_k, len_without_k)

    return max(ans, len(ends))

def main():
    data = input().split()
    index = 0
    while index < len(data):
        n = int(data[index])
        index += 1
        k = int(data[index])
        index += 1
        arr = list(map(int, data[index:index+n]))
        index += n
        print(compute(arr, k))

if __name__ == "__main__":
    main()
