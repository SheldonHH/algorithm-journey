def find_substring_in_wrapround_string(s: str) -> int:
    n = len(s)
    s_index = [ord(char) - ord('a') for char in s]  # 将字符转换为从0开始的索引，即 'a' -> 0, 'b' -> 1, ..., 'z' -> 25

    dp = [0] * 26  # dp[i] 表示以字符 'a'+i 结尾的最长子字符串的长度
    dp[s_index[0]] = 1
    cur, pre, len = 0, 0, 1  # cur当前字符索引，pre前一个字符索引，len当前有效长度

    for i in range(1, n):
        cur = s_index[i]
        pre = s_index[i - 1]
        # 检查当前字符是否能延续前一个字符形成环绕子字符串
        if (pre == 25 and cur == 0) or (pre + 1 == cur):
            len += 1  # 延伸长度
        else:
            len = 1  # 重新开始
        dp[cur] = max(dp[cur], len)  # 更新以当前字符结尾的最大长度

    return sum(dp)  # 统计所有不同子字符串的长度之和

# 示例使用
s = "zab"
print("环绕字符串中唯一的子字符串数量:", find_substring_in_wrapround_string(s))
