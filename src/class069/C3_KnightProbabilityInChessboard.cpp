#include <vector>
using namespace std;

class Code03_KnightProbabilityInChessboard {
public:
    double knightProbability(int n, int k, int row, int col) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        return f(n, row, col, k, dp);
    }

    // 从(i,j)出发还有k步要走，返回最后在棋盘上的概率
    double f(int n, int i, int j, int k, vector<vector<vector<double>>>& dp) {
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return 0.0;
        }
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        double ans = 0.0;
        if (k == 0) {
            ans = 1.0;
        } else {
            ans += f(n, i - 2, j + 1, k - 1, dp) / 8.0;
            ans += f(n, i - 1, j + 2, k - 1, dp) / 8.0;
            ans += f(n, i + 1, j + 2, k - 1, dp) / 8.0;
            ans += f(n, i + 2, j + 1, k - 1, dp) / 8.0;
            ans += f(n, i + 2, j - 1, k - 1, dp) / 8.0;
            ans += f(n, i + 1, j - 2, k - 1, dp) / 8.0;
            ans += f(n, i - 1, j - 2, k - 1, dp) / 8.0;
            ans += f(n, i - 2, j - 1, k - 1, dp) / 8.0;
        }
        dp[i][j][k] = ans;
        return ans;
    }
};
