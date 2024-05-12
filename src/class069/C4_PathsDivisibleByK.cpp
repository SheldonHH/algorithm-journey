#include <vector>
using namespace std;

class Code04_PathsDivisibleByK {
public:
    static const int mod = 1000000007;

    // 使用递归方法解决
    static int numberOfPaths1(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        return f1(grid, n, m, k, 0, 0, 0);
    }

    // i, j 当前位置，r 需要的余数
    static int f1(vector<vector<int>>& grid, int n, int m, int k, int i, int j, int r) {
        if (i == n - 1 && j == m - 1) {
            return grid[i][j] % k == r ? 1 : 0;
        }
        int need = (k + r - (grid[i][j] % k)) % k;
        int ans = 0;
        if (i + 1 < n) {
            ans = f1(grid, n, m, k, i + 1, j, need);
        }
        if (j + 1 < m) {
            ans = (ans + f1(grid, n, m, k, i, j + 1, need)) % mod;
        }
        return ans;
    }

    // 使用记忆化搜索优化
    static int numberOfPaths2(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return f2(grid, n, m, k, 0, 0, 0, dp);
    }

    // i, j 当前位置，r 需要的余数
    static int f2(vector<vector<int>>& grid, int n, int m, int k, int i, int j, int r, vector<vector<vector<int>>>& dp) {
        if (i == n - 1 && j == m - 1) {
            return grid[i][j] % k == r ? 1 : 0;
        }
        if (dp[i][j][r] != -1) {
            return dp[i][j][r];
        }
        int need = (k + r - (grid[i][j] % k)) % k;
        int ans = 0;
        if (i + 1 < n) {
            ans = f2(grid, n, m, k, i + 1, j, need, dp);
        }
        if (j + 1 < m) {
            ans = (ans + f2(grid, n, m, k, i, j + 1, need, dp)) % mod;
        }
        dp[i][j][r] = ans;
        return ans;
    }

    // 动态规划方法
    static int numberOfPaths3(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));
        dp[n - 1][m - 1][grid[n - 1][m - 1] % k] = 1;
        for (int i = n - 2; i >= 0; i--) {
            for (int r = 0; r < k; r++) {
                dp[i][m - 1][r] = dp[i + 1][m - 1][(k + r - grid[i][m - 1] % k) % k];
            }
        }
        for (int j = m - 2; j >= 0; j--) {
            for (int r = 0; r < k; r++) {
                dp[n - 1][j][r] = dp[n - 1][j + 1][(k + r - grid[n - 1][j] % k) % k];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                for (int r = 0; r < k; r++) {
                    int need = (k + r - grid[i][j] % k) % k;
                    dp[i][j][r] = dp[i + 1][j][need];
                    dp[i][j][r] = (dp[i][j][r] + dp[i][j + 1][need]) % mod;
                }
            }
        }
        return dp[0][0][0];
    }
};
