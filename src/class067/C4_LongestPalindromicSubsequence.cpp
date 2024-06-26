#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 最长回文子序列
// 给定一个字符串s，找到其中最长的回文子序列，并返回该序列的长度
class Code04_LongestPalindromicSubsequence {
public:
    // 区间动态规划解法
    static int longestPalindromeSubseq1(const string& str) {
        const char* s = str.c_str();
        int n = str.size();
        return f1(s, 0, n - 1);
    }

    // s[l...r]最长回文子序列长度
    static int f1(const char* s, int l, int r) {
        if (l == r) {
            return 1;
        }
        if (l + 1 == r) {
            return s[l] == s[r] ? 2 : 1;
        }
        if (s[l] == s[r]) {
            return 2 + f1(s, l + 1, r - 1);
        } else {
            return max(f1(s, l + 1, r), f1(s, l, r - 1));
        }
    }

    static int longestPalindromeSubseq2(const string& str) {
        const char* s = str.c_str();
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        return f2(s, 0, n - 1, dp);
    }

    static int f2(const char* s, int l, int r, vector<vector<int>>& dp) {
        if (l == r) {
            return 1;
        }
        if (l + 1 == r) {
            return s[l] == s[r] ? 2 : 1;
        }
        if (dp[l][r] != 0) {
            return dp[l][r];
        }
        int ans;
        if (s[l] == s[r]) {
            ans = 2 + f2(s, l + 1, r - 1, dp);
        } else {
            ans = max(f2(s, l + 1, r, dp), f2(s, l, r - 1, dp));
        }
        dp[l][r] = ans;
        return ans;
    }

    static int longestPalindromeSubseq3(const string& str) {
        const char* s = str.c_str();
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int l = n - 1; l >= 0; l--) {
            dp[l][l] = 1;
            if (l + 1 < n) {
                dp[l][l + 1] = s[l] == s[l + 1] ? 2 : 1;
            }
            for (int r = l + 2; r < n; r++) {
                if (s[l] == s[r]) {
                    dp[l][r] = 2 + dp[l + 1][r - 1];
                } else {
                    dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }

    static int longestPalindromeSubseq4(const string& str) {
        const char* s = str.c_str();
        int n = str.size();
        vector<int> dp(n, 0);
        for (int l = n - 1, leftDown = 0, backup; l >= 0; l--) {
            dp[l] = 1;
            if (l + 1 < n) {
                leftDown = dp[l + 1];
                dp[l + 1] = s[l] == s[l + 1] ? 2 : 1;
            }
            for (int r = l + 2; r < n; r++) {
                backup = dp[r];
                if (s[l] == s[r]) {
                    dp[r] = 2 + leftDown;
                } else {
                    dp[r] = max(dp[r], dp[r - 1]);
                }
                leftDown = backup;
            }
        }
        return dp[n - 1];
    }
};
