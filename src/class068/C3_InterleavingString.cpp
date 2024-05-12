#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Dynamic programming solution
    bool isInterleave1(string str1, string str2, string str3) {
        if (str1.length() + str2.length() != str3.length()) {
            return false;
        }
        int n = str1.length();
        int m = str2.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = (str1[i - 1] == str3[i - 1]) && dp[i - 1][0];
        }
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = (str2[j - 1] == str3[j - 1]) && dp[0][j - 1];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = ((str1[i - 1] == str3[i + j - 1]) && dp[i - 1][j]) || ((str2[j - 1] == str3[i + j - 1]) && dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

    // Space optimized dynamic programming solution
    bool isInterleave2(string str1, string str2, string str3) {
        if (str1.length() + str2.length() != str3.length()) {
            return false;
        }
        int n = str1.length();
        int m = str2.length();
        vector<bool> dp(m + 1, false);
        dp[0] = true;
        for (int j = 1; j <= m; ++j) {
            dp[j] = (str2[j - 1] == str3[j - 1]) && dp[j - 1];
        }
        for (int i = 1; i <= n; ++i) {
            dp[0] = (str1[i - 1] == str3[i - 1]) && dp[0];
            for (int j = 1; j <= m; ++j) {
                dp[j] = ((str1[i - 1] == str3[i + j - 1]) && dp[j]) || ((str2[j - 1] == str3[i + j - 1]) && dp[j - 1]);
            }
        }
        return dp[m];
    }
};
