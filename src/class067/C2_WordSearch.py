class WordSearch:
    # 单词搜索（无法转化为动态规划）
    # 给定一个 m x n 的二维字符网格 board 和一个字符串 word
    # 如果 word 存在于网格中，返回 true；否则返回 false。
    # 单词必须按照字母顺序，通过相邻的单元格内的字母构成
    # “相邻”单元格是那些水平相邻或垂直相邻的单元格
    # 同一个单元格内的字母不允许被重复使用
    # 测试链接 : https://leetcode.cn/problems/word-search/

    def exist(self, board, word):
        # 转换word为字符数组方便操作
        w = list(word)
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.f(board, i, j, w, 0):
                    return True
        return False

    # 从(i,j)出发，检查是否能够形成word[k...]
    # 递归中标记已使用的单元格，避免重复使用
    def f(self, b, i, j, w, k):
        if k == len(w):
            return True
        if i < 0 or i >= len(b) or j < 0 or j >= len(b[0]) or b[i][j] != w[k]:
            return False
        
        # 暂存当前字符，并在board上暂时置空，防止再次使用
        tmp = b[i][j]
        b[i][j] = None  # 使用 None 来代替字符的占用
        # 递归探索上下左右四个方向
        ans = self.f(b, i - 1, j, w, k + 1) or \
              self.f(b, i + 1, j, w, k + 1) or \
              self.f(b, i, j - 1, w, k + 1) or \
              self.f(b, i, j + 1, w, k + 1)
        
        # 恢复当前格子的字符
        b[i][j] = tmp
        return ans
