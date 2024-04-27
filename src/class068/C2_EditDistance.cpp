#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class EditDistance {
public:
    // Basic dynamic programming approach
    static int editDistance1(const string& str1, const string& str2, int a, int b, int c) {
        const char* s1 = str1.c_str();
        const char* s2 = str2.c_str();
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            dp[i][0] = i * b;
        }
        for (int j = 1; j <= m; j++) {
            dp[0][j] = j * a;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(min(dp[i - 1][j] + b, dp[i][j - 1] + a), dp[i - 1][j - 1] + c);
                }
            }
        }
        return dp[n][m];
    }

    // Optimized dynamic programming approach with less redundancy
    static int editDistance2(const string& str1, const string& str2, int a, int b, int c) {
        const char* s1 = str1.c_str();
        const char* s2 = str2.c_str();
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            dp[i][0] = i * b;
        }
        for (int j = 1; j <= m; j++) {
            dp[0][j] = j * a;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(min(dp[i - 1][j] + b, dp[i][j - 1] + a), dp[i - 1][j - 1] + c);
                }
            }
        }
        return dp[n][m];
    }

    // Space optimized dynamic programming approach
    static int editDistance3(const string& str1, const string& str2, int a, int b, int c) {
        const char* s1 = str1.c_str();
        const char* s2 = str2.c_str();
        int n = str1.length();
        int m = str2.length();
        vector<int> dp(m + 1, 0);

        for (int j = 1; j <= m; j++) {
            dp[j] = j * a;
        }

        for (int i = 1; i <= n; i++) {
            int leftUp = (i - 1) * b;
            dp[0] = i * b;
            for (int j = 1, backUp; j <= m; j++) {
                backUp = dp[j];
                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = leftUp;
                } else {
                    dp[j] = min(min(dp[j] + b, dp[j - 1] + a), leftUp + c);
                }
                leftUp = backUp;
            }
        }
        return dp[m];
    }
};
