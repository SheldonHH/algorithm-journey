class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if s == "":
            return True  # 如果 `s` 是空字符串，直接返回 True

        j = 0  # 指向 `s` 的指针

        for idx, c in enumerate(t):
            # 如果当前 `t` 中的字符与 `s` 中的字符匹配，则移动 `s` 指针
            print("idx: , c:{:?}", idx, c)
            if j < len(s) and s[j] == c:
                j += 1
                # 如果 `j` 达到 `s` 的末尾，说明 `s` 是 `t` 的子序列
                if j == len(s):
                    return True

        # 如果 `t` 遍历结束而 `s` 没有完全匹配上，则返回 False
        return False

def main():
    # 给定的字符串 `s` 和 `t`
    t = ['e', 'f', 'a', 'b', 'x', 'b', 'c', 'y', 'a', 'b', 'c']
    s = ['a', 'b', 'c']

    # 将 `s` 和 `t` 转换为字符串
    s_str = ''.join(s)
    t_str = ''.join(t)

    # 创建 `Solution` 类实例
    solution = Solution()

    # 调用 `isSubsequence` 函数并打印结果
    result = solution.isSubsequence(s_str, t_str)
    print(f"Is '{s_str}' a subsequence of '{t_str}'? {result}")

# 运行 main 函数
if __name__ == "__main__":
    main()
