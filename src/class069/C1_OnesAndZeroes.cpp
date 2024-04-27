#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Code01_OnesAndZeroes {
public:
    int zeros, ones;

    void zerosAndOnes(const string& str) {
        zeros = 0;
        ones = 0;
        for (char c : str) {
            if (c == '0') {
                zeros++;
            } else {
                ones++;
            }
        }
    }

    int findMaxForm1(vector<string>& strs, int m, int n) {
        return f1(strs, 0, m, n);
    }

    int f1(vector<string>& strs, int i, int z, int o) {
        if (i == strs.size()) {
            return 0;
        }
        int p1 = f1(strs, i + 1, z, o);
        int p2 = 0;
        zerosAndOnes(strs[i]);
        if (zeros <= z && ones <= o) {
            p2 = 1 + f1(strs, i + 1, z - zeros, o - ones);
        }
        return max(p1, p2);
    }

    int findMaxForm2(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return f2(strs, 0, m, n, dp);
    }

    int f2(vector<string>& strs, int i, int z, int o, vector<vector<vector<int>>>& dp) {
        if (i == strs.size()) {
            return 0;
        }
        if (dp[i][z][o] != -1) {
            return dp[i][z][o];
        }
        int p1 = f2(strs, i + 1, z, o, dp);
        int p2 = 0;
        zerosAndOnes(strs[i]);
        if (zeros <= z && ones <= o) {
            p2 = 1 + f2(strs, i + 1, z - zeros, o - ones, dp);
        }
        int ans = max(p1, p2);
        dp[i][z][o] = ans;
        return ans;
    }

    int findMaxForm3(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int i = len - 1; i >= 0; i--) {
            zerosAndOnes(strs[i]);
            for (int z = 0; z <= m; z++) {
                for (int o = 0; o <= n; o++) {
                    int p1 = dp[i + 1][z][o];
                    int p2 = 0;
                    if (zeros <= z && ones <= o) {
                        p2 = 1 + dp[i + 1][z - zeros][o - ones];
                    }
                    dp[i][z][o] = max(p1, p2);
                }
            }
        }
        return dp[0][m][n];
    }

    int findMaxForm4(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (string s : strs) {
            zerosAndOnes(s);
            for (int z = m; z >= zeros; z--) {
                for (int o = n; o >= ones; o--) {
                    dp[z][o] = max(dp[z][o], 1 + dp[z - zeros][o - ones]);
                }
            }
        }
        return dp[m][n];
    }
};
