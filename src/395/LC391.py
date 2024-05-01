class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        # 初始化指向 s 和 t 的指针
        i, j = 0, 0

        # 遍历 t，直到遍历完 t 或找到 s 的所有字符
        while i < len(s) and j < len(t):
            # 如果当前字符相同，移动 s 的指针
            if s[i] == t[j]:
                i += 1
            # 总是移动 t 的指针
            j += 1

        # 如果 i 走到了 s 的结尾，说明 s 是 t 的子序列
        return i == len(s)
