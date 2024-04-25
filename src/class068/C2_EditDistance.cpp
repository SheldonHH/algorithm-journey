#include <vector>
#include <string>
#include <algorithm>

class EditDistance {
public:
    // 原初尝试版
    static int editDistance1(const std::string& str1, const std::string& str2, int a, int b, int c) {
        int n = str1.size();
        int m = str2.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            dp[i][0] = i * b;
        }
        for (int j = 1; j <= m; j++) {
            dp[0][j] = j * a;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int p1 = INT_MAX;
                if (str1[i - 1] == str2[j - 1]) {
                    p1 = dp[i - 1][j - 1];
                }
                int p2 = (str1[i - 1] != str2[j - 1]) ? dp[i - 1][j - 1] + c : INT_MAX;
                int p3 = dp[i][j - 1] + a;
                int p4 = dp[i - 1][j] + b;
                dp[i][j] = std::min({p1, p2, p3, p4});
            }
        }

        return dp[n][m];
    }

    // 枚举小优化版
    static int editDistance2(const std::string& str1, const std::string& str2, int a, int b, int c) {
        int n = str1.size();
        int m = str2.size();
        std::vector<std::vector<int>> dp(n + 
