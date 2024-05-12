# 构造数组，取AND,结果是x
# 让数组最大的数，尽可能的小

# 构造所有符合要求的1
def abc(n, x):
    j = 0
    t = ~x
    while n >> j: # 还有比特没有枚举到，就继续循环
        lb = t & -t
        bit = n>> j&1
        x |= bit * lb # 相当于if else
        j += 1
        t ^= lb
    return x

    


    # i指向目标空位x
    # j指向n-1中的比特
    n -= 1# n的第j个比特，天蝎到x的第j个比特
    i = j = 0
    while n>>j:
        # 是空位
        if (x >> i & 1) == 0:
            bit = n >> j & 1 # n的第j个比特
            # 左移动i为 

