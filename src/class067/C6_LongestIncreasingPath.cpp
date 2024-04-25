#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 功能：计算矩阵中的最长递增路径的长度
// 参数：二维整数矩阵grid
// 返回值：最长递增路径的长度
int longestIncreasingPath1(const vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, f1(grid, i, j));
        }
    }
    return ans;
}

// 功能：从(i, j)出发，能走出来的最长递增路径长度
// 参数：grid为二维矩阵，i和j为当前位置
// 返回值：从(i, j)出发的最长递增路径长度
int f1(const vector<vector<int>>& grid, int i, int j) {
    int n = grid.size();
    int m = grid[0].size();
    int next = 0;
    if (i > 0 && grid[i][j] < grid[i - 1][j]) {
        next = max(next, f1(grid, i - 1, j));
    }
    if (i + 1 < n && grid[i][j] < grid[i + 1][j]) {
        next = max(next, f1(grid, i + 1, j));
    }
    if (j > 0 && grid[i][j] < grid[i][j - 1]) {
        next = max(next, f1(grid, i, j - 1));
    }
    if (j + 1 < m && grid[i][j] < grid[i][j + 1]) {
        next = max(next, f1(grid, i, j + 1));
    }
    return next + 1;
}

// 使用记忆化搜索优化求解最长递增路径
int longestIncreasingPath2(const vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, f2(grid, i, j, dp));
        }
    }
    return ans;
}

// 使用动态规划数组dp存储已计算的结果，减少重复计算
int f2(const vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
    if (dp[i][j] != 0) {
        return dp[i][j];
    }
    int n = grid.size();
    int m = grid[0].size();
    int next = 0;
    if (i > 0 && grid[i][j] < grid[i - 1][j]) {
        next = max(next, f2(grid, i - 1, j, dp));
    }
    if (i + 1 < n && grid[i][j] < grid[i + 1][j]) {
        next = max(next, f2(grid, i + 1, j, dp));
    }
    if (j > 0 && grid[i][j] < grid[i][j - 1]) {
        next = max(next, f2(grid, i, j - 1, dp));
    }
    if (j + 1 < m && grid[i][j] < grid[i][j + 1]) {
        next = max(next, f2(grid, i, j + 1, dp));
    }
    dp[i][j] = next + 1;
    return dp[i][j];
}

int main() {
    // 例子：定义一个4x4的矩阵，并调用函数计算最长递增路径的长度
    vector<vector<int>> matrix = {
        {9,9,4},
        {6,6,8},
        {2,1,1}
    };
    cout << "最长递增路径长度: " << longestIncreasingPath2(matrix) << endl;
    return 0;
}
