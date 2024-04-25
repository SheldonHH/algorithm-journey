#include <vector>
#include <string>

class Code01_DistinctSubsequences {
public:
    // 动态规划方法
    static int numDistinct1(const std::string& str, const std::string& target) {
        int n = str.size();
        int m = target.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

        // 初始化，s的任何前缀形成的序列都包含空序列
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j]; // 不使用s中的当前字符
                if (str[i - 1] == target[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1]; // 使用s中的当前字符
                }
            }
        }
        return dp[n][m];
    }

    // 动态规划，空间优化版
    static int numDistinct2(const std::string& str, const std::string& target) {
        int n = str.size();
        int m = target.size();
        std::vector<int> dp(m + 1, 0);
        dp[0] = 1; // 任何字符串的子序列都包含空序列

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) { // 从后向前更新，避免干扰未处理的数据
                if (str[i - 1] == target[j - 1]) {
                    dp[j] += dp[j - 1]; // 更新dp[j]，使用当前s中的字符
                }
            }
        }
        return dp[m];
    }
};
