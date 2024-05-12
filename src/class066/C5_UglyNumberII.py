def nth_ugly_number(n: int) -> int:
    """
    返回第n个丑数。丑数定义为只包含质因数2、3或5的正整数。
    """
    dp = [0] * (n + 1)  # 创建一个数组来存储丑数，从1到n
    dp[1] = 1  # 第一个丑数是1
    i2 = i3 = i5 = 1  # 用于跟踪2、3、5的倍数位置

    for i in range(2, n + 1):
        a = dp[i2] * 2
        b = dp[i3] * 3
        c = dp[i5] * 5
        cur = min(a, b, c)  # 选择最小值作为下一个丑数

        if cur == a:  # 更新对应因子的索引
            i2 += 1
        if cur == b:
            i3 += 1
        if cur == c:
            i5 += 1
        
        dp[i] = cur  # 将选定的丑数存储在dp数组中

    return dp[n]  # 返回第n个丑数

# Example usage:
print(nth_ugly_number(10))  # 输出第10个丑数
