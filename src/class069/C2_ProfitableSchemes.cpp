#include <vector>
using namespace std;

class Code02_ProfitableSchemes {
public:
    static const int mod = 1000000007;

    // Recursive approach
    static int profitableSchemes1(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        return f1(group, profit, 0, n, minProfit);
    }

    static int f1(vector<int>& g, vector<int>& p, int i, int r, int s) {
        if (r <= 0) {
            return s <= 0 ? 1 : 0;
        }
        if (i == g.size()) {
            return s <= 0 ? 1 : 0;
        }
        int p1 = f1(g, p, i + 1, r, s);
        int p2 = 0;
        if (g[i] <= r) {
            p2 = f1(g, p, i + 1, r - g[i], s - p[i]);
        }
        return (p1 + p2) % mod;
    }

    // Memoization approach
    static int profitableSchemes2(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));
        return f2(group, profit, 0, n, minProfit, dp);
    }

    static int f2(vector<int>& g, vector<int>& p, int i, int r, int s, vector<vector<vector<int>>>& dp) {
        if (r <= 0) {
            return s == 0 ? 1 : 0;
        }
        if (i == g.size()) {
            return s == 0 ? 1 : 0;
        }
        if (dp[i][r][s] != -1) {
            return dp[i][r][s];
        }
        int p1 = f2(g, p, i + 1, r, s, dp);
        int p2 = 0;
        if (g[i] <= r) {
            p2 = f2(g, p, i + 1, r - g[i], max(0, s - p[i]), dp);
        }
        int ans = (p1 + p2) % mod;
        dp[i][r][s] = ans;
        return ans;
    }

    // Dynamic Programming approach
    static int profitableSchemes3(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        for (int r = 0; r <= n; r++) {
            dp[r][0] = 1;
        }
        int m = group.size();
        for (int i = m - 1; i >= 0; i--) {
            for (int r = n; r >= 0; r--) {
                for (int s = minProfit; s >= 0; s--) {
                    int p1 = dp[r][s];
                    int p2 = group[i] <= r ? dp[r - group[i]][max(0, s - profit[i])] : 0;
                    dp[r][s] = (p1 + p2) % mod;
                }
            }
        }
        return dp[n][minProfit];
    }
};
