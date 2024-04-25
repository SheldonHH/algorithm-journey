#include <vector>
#include <string>

const int MOD = 1000000007;

// 动态规划求解解码方法II的函数
int numDecodings(const std::string& s) {
    int n = s.size();
    std::vector<long long> dp(n + 1, 0);
    dp[n] = 1;  // 边界条件，空字符串有1种解码方式

    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            dp[i] = 0;  // '0'不能单独解码
        } else {
            // 单个字符解码
            dp[i] = (s[i] == '*' ? 9 : 1) * dp[i + 1] % MOD;

            // 双字符组合解码
            if (i + 1 < n) {
                if (s[i] != '*') {
                    if (s[i + 1] != '*') {
                        int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                        if (num <= 26)
                            dp[i] = (dp[i] + dp[i + 2]) % MOD;
                    } else {
                        if (s[i] == '1')
                            dp[i] = (dp[i] + dp[i + 2] * 9) % MOD;
                        else if (s[i] == '2')
                            dp[i] = (dp[i] + dp[i + 2] * 6) % MOD;
                    }
                } else {
                    if (s[i + 1] != '*') {
                        if (s[i + 1] <= '6')
                            dp[i] = (dp[i] + dp[i + 2] * 2) % MOD;
                        else
                            dp[i] = (dp[i] + dp[i + 2]) % MOD;
                    } else {
                        dp[i] = (dp[i] + dp[i + 2] * 15) % MOD;
                    }
                }
            }
        }
    }

    return dp[0];
}

int main() {
    std::string s = "1*";
    std::cout << "Number of ways to decode \"" << s << "\": " << numDecodings(s) << std::endl;
    return 0;
}

// 2. C++ 版本：递归暴力尝试（带备忘录）
#include <iostream>
#include <vector>
#include <string>

const int MOD = 1000000007;

long long f2(const std::string& s, int i, std::vector<long long>& dp) {
    int n = s.length();
    if (i == n) return 1;  // 到达字符串末尾，返回1
    if (s[i] == '0') return 0;  // 遇到'0'，返回0
    if (dp[i] != -1) return dp[i];  // 使用备忘录避免重复计算

    long long ans = f2(s, i + 1, dp) * (s[i] == '*' ? 9 : 1) % MOD;  // 单个字符解码
    if (i + 1 < n) {
        if (s[i] != '*') {
            if (s[i + 1] != '*') {
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if (num <= 26) ans = (ans + f2(s, i + 2, dp)) % MOD;
            } else {
                if (s[i] == '1') ans = (ans + f2(s, i + 2, dp) * 9) % MOD;
                else if (s[i] == '2') ans = (ans + f2(s, i + 2, dp) * 6) % MOD;
            }
        } else {
            if (s[i + 1] != '*') {
                ans = (ans + f2(s, i + 2, dp) * (s[i + 1] <= '6' ? 2 : 1)) % MOD;
            } else {
                ans = (ans + f2(s, i + 2, dp) * 15) % MOD;
            }
        }
    }
    return dp[i] = ans;
}

int numDecodings2(const std::string& s) {
    std::vector<long long> dp(s.size(), -1);
    return f2(s, 0, dp);
}



// 3. C++ 版本：动态规划，使用数组 dp
int numDecodings3(const std::string& s) {
    int n = s.length();
    std::vector<long long> dp(n + 1, 0);
    dp[n] = 1;  // 初始化边界条件
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') dp[i] = 0;
        else {
            dp[i] = dp[i + 1] * (s[i] == '*' ? 9 : 1) % MOD;  // 单字符解码
            if (i + 1 < n) {
                // 处理双字符解码
                if (s[i] != '*') {
                    if (s[i + 1] != '*') {
                        int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                        if (num <= 26) dp[i] = (dp[i] + dp[i + 2]) % MOD;
                    } else {
                        if (s[i] == '1') dp[i] = (dp[i] + dp[i + 2] * 9) % MOD;
                        else if (s[i] == '2') dp[i] = (dp[i] + dp[i + 2] * 6) % MOD;
                    }
                } else {
                    if (s[i + 1] != '*') {
                        dp[i] = (dp[i] + dp[i + 2] * (s[i + 1] <= '6' ? 2 : 1)) % MOD;
                    } else {
                        dp[i] = (dp[i] + dp[i + 2] * 15) % MOD;
                    }
                }
            }
        }
    }
    return dp[0];
}



// 4. C++ 版本：动态规划，优化空间复杂度
int numDecodings4(const std::string& s) {
    int n = s.length();
    long long cur = 0, next = 1, nextNext = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] != '0') {
            cur = next * (s[i] == '*' ? 9 : 1) % MOD;
            if (i + 1 < n) {
                if (s[i] != '*') {
                    if (s[i + 1] != '*') {
                        if ((s[i] - '0') * 10 + (s[i + 1] - '0') <= 26) {
                            cur = (cur + nextNext) % MOD;
                        }
                    } else {
                        if (s[i] == '1') {
                            cur = (cur + nextNext * 9) % MOD;
                        } else if (s[i] == '2') {
                            cur = (cur + nextNext * 6) % MOD;
                        }
                    }
                } else {
                    if (s[i + 1] != '*') {
                        cur = (cur + nextNext * (s[i + 1] <= '6' ? 2 : 1)) % MOD;
                    } else {
                        cur = (cur + nextNext * 15) % MOD;
                    }
                }
            }
        }
        nextNext = next;
        next = cur;
        cur = 0;
    }
    return next;
}
