def edit_distance1(str1, str2, a, b, c):
    """
    原初尝试版
    a : str1中插入1个字符的代价
    b : str1中删除1个字符的代价
    c : str1中改变1个字符的代价
    返回从str1转化成str2的最低代价
    """
    n, m = len(str1), len(str2)
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        dp[i][0] = i * b
    for j in range(1, m + 1):
        dp[0][j] = j * a
    
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            p1 = float('inf')
            if str1[i - 1] == str2[j - 1]:
                p1 = dp[i - 1][j - 1]
            p2 = dp[i - 1][j - 1] + c if str1[i - 1] != str2[j - 1] else float('inf')
            p3 = dp[i][j - 1] + a
            p4 = dp[i - 1][j] + b
            dp[i][j] = min(p1, p2, p3, p4)
    
    return dp[n][m]

def edit_distance2(str1, str2, a, b, c):
    """
    枚举小优化版
    a : str1中插入1个字符的代价
    b : str1中删除1个字符的代价
    c : str1中改变1个字符的代价
    返回从str1转化成str2的最低代价
    """
    n, m = len(str1), len(str2)
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        dp[i][0] = i * b
    for j in range(1, m + 1):
        dp[0][j] = j * a
    
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if str1[i - 1] == str2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = min(dp[i - 1][j] + b, dp[i][j - 1] + a, dp[i - 1][j - 1] + c)
    
    return dp[n][m]

def edit_distance3(str1, str2, a, b, c):
    """
    空间压缩
    a : str1中插入1个字符的代价
    b : str1中删除1个字符的代价
    c : str1中改变1个字符的代价
    返回从str1转化成str2的最低代价
    """
    n, m = len(str1), len(str2)
    dp = [0] * (m + 1)
    
    for j in range(1, m + 1):
        dp[j] = j * a
    
    for i in range(1, n + 1):
        left_up = (i - 1) * b
        dp[0] = i * b
        for j in range(1, m + 1):
            back_up = dp[j]
            if str1[i - 1] == str2[j - 1]:
                dp[j] = left_up
            else:
                dp[j] = min(dp[j] + b, dp[j - 1] + a, left_up + c)
            left_up = back_up
    
    return dp[m]
