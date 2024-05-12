#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 最长公共子序列
    // 给定两个字符串text1和text2
    // 返回这两个字符串的最长公共子序列的长度
    // 如果不存在公共子序列，返回0
    // 两个字符串的公共子序列是这两个字符串所共同拥有的子序列
    int longestCommonSubsequence1(string str1, string str2) {
        vector<char> s1(str1.begin(), str1.end());
        vector<char> s2(str2.begin(), str2.end());
        int n = s1.size();
        int m = s2.size();
        return f1(s1, s2, n - 1, m - 1);
    }

    // s1[0...i1]与s2[0...i2]最长公共子序列长度
    int f1(vector<char>& s1, vector<char>& s2, int i1, int i2) {
        if (i1 < 0 || i2 < 0) {
            return 0;
        }
        int p1 = f1(s1, s2, i1 - 1, i2 - 1);
        int p2 = f1(s1, s2, i1 - 1, i2);
        int p3 = f1(s1, s2, i1, i2 - 1);
        int p4 = s1[i1] == s2[i2] ? (p1 + 1) : 0;
        return max({p1, p2, p3, p4});
    }

    // 为了避免很多边界讨论
    // 很多时候往往不用下标来定义尝试，而是用长度来定义尝试
    // 因为长度最短是0，而下标越界的话讨论起来就比较麻烦
    int longestCommonSubsequence2(string str1, string str2) {
        vector<char> s1(str1.begin(), str1.end());
        vector<char> s2(str2.begin(), str2.end());
        int n = s1.size();
        int m = s2.size();
        return f2(s1, s2, n, m);
    }

    // s1[前缀长度为len1]对应s2[前缀长度为len2]
    // 最长公共子序列长度
    int f2(vector<char>& s1, vector<char>& s2, int len1, int len2) {
        if (len1 == 0 || len2 == 0) {
            return 0;
        }
        int ans;
        if (s1[len1 - 1] == s2[len2 - 1]) {
            ans = f2(s1, s2, len1 - 1, len2 - 1) + 1;
        } else {
            ans = max(f2(s1, s2, len1 - 1, len2), f2(s1, s2, len1, len2 - 1));
        }
        return ans;
    }

    // 记忆化搜索
    int longestCommonSubsequence3(string str1, string str2) {
        vector<char> s1(str1.begin(), str1.end());
        vector<char> s2(str2.begin(), str2.end());
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f3(s1, s2, n, m, dp);
    }

    int f3(vector<char>& s1, vector<char>& s2, int len1, int len2, vector<vector<int>>& dp) {
        if (len1 == 0 || len2 == 0) {
            return 0;
        }
        if (dp[len1][len2] != -1) {
            return dp[len1][len2];
        }
        int ans;
        if (s1[len1 - 1] == s2[len2 - 1]) {
            ans = f3(s1, s2, len1 - 1, len2 - 1, dp) + 1;
        } else {
            ans = max(f3(s1, s2, len1 - 1, len2, dp), f3(s1, s2, len1, len2 - 1, dp));
        }
        dp[len1][len2] = ans;
        return ans;
    }

    // 严格位置依赖的动态规划
    int longestCommonSubsequence4(string str1, string str2) {
        vector<char> s1(str1.begin(), str1.end());
        vector<char> s2(str2.begin(), str2.end());
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int len1 = 1; len1 <= n; len1++) {
            for (int len2 = 1; len2 <= m; len2++) {
                if (s1[len1 - 1] == s2[len2 - 1]) {
                    dp[len1][len2] = 1 + dp[len1 - 1][len2 - 1];
                } else {
                    dp[len1][len2] = max(dp[len1 - 1][len2], dp[len1][len2 - 1]);
                }
            }
        }
        return dp[n][m];
    }

    // 严格位置依赖的动态规划 + 空间压缩
    int longestCommonSubsequence5(string str1, string str2) {
        vector<char> s1, s2;
        if (str1.length() >= str2.length()) {
            s1 = vector<char>(str1.begin(), str1.end());
            s2 = vector<char>(str2.begin(), str2.end());
        } else {
            s1 = vector<char>(str2.begin(), str2.end());
            s2 = vector<char>(str1.begin(), str1.end());
        }
        int n = s1.size();
        int m = s2.size();
        vector<int> dp(m + 1, 0);
        for (int len1 = 1; len1 <= n; len1++) {
            int leftUp = 0, backup;
            for (int len2 = 1; len2 <= m; len2++) {
                backup = dp[len2];
                if (s1[len1 - 1] == s2[len2 - 1]) {
                    dp[len2] = 1 + leftUp;
                } else {
                    dp[len2] = max(dp[len2], dp[len2 - 1]);
                }
                leftUp = backup;
            }
        }
        return dp[m];
    }
};
