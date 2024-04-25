#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 单词搜索（无法改成动态规划）
    // 给定一个 m x n 二维字符网格 board 和一个字符串单词 word
    // 如果 word 存在于网格中，返回 true ；否则，返回 false 。
    // 单词必须按照字母顺序，通过相邻的单元格内的字母构成
    // 其中"相邻"单元格是那些水平相邻或垂直相邻的单元格
    // 同一个单元格内的字母不允许被重复使用
    bool exist(vector<vector<char>>& board, string word) {
        vector<char> w(word.begin(), word.end());
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (f(board, i, j, w, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    // 因为board会改其中的字符
    // 用来标记哪些字符无法再用
    // 带路径的递归无法改成动态规划或者说没必要
    // 从(i,j)出发，来到w[k]，请问后续能不能把word走出来w[k...]
    bool f(vector<vector<char>>& b, int i, int j, vector<char>& w, int k) {
        if (k == w.size()) {
            return true;
        }
        if (i < 0 || i == b.size() || j < 0 || j == b[0].size() || b[i][j] != w[k]) {
            return false;
        }
        // 不越界，b[i][j] == w[k]
        char tmp = b[i][j];
        b[i][j] = 0;  // Temporarily mark the cell as visited
        bool ans = f(b, i - 1, j, w, k + 1)    // Move up
                || f(b, i + 1, j, w, k + 1)    // Move down
                || f(b, i, j - 1, w, k + 1)    // Move left
                || f(b, i, j + 1, w, k + 1);   // Move right
        b[i][j] = tmp;  // Restore the original character
        return ans;
    }
};
