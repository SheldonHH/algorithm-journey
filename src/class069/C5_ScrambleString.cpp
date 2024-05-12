#include <vector>
#include <string>
using namespace std;

class Code05_ScrambleString {
public:
    bool isScramble1(const string& str1, const string& str2) {
        int n = str1.length();
        return f1(str1, 0, n - 1, str2, 0, n - 1);
    }

    bool f1(const string& s1, int l1, int r1, const string& s2, int l2, int r2) {
        if (l1 == r1) {
            return s1[l1] == s2[l2];
        }
        for (int i = l1, j = l2; i < r1; i++, j++) {
            if (f1(s1, l1, i, s2, l2, j) && f1(s1, i + 1, r1, s2, j + 1, r2)) {
                return true;
            }
        }
        for (int i = l1, j = r2; i < r1; i++, j--) {
            if (f1(s1, l1, i, s2, j, r2) && f1(s1, i + 1, r1, s2, l2, j - 1)) {
                return true;
            }
        }
        return false;
    }

    bool isScramble2(const string& str1, const string& str2) {
        int n = str1.length();
        return f2(str1, str2, 0, 0, n);
    }

    bool f2(const string& s1, const string& s2, int l1, int l2, int len) {
        if (len == 1) {
            return s1[l1] == s2[l2];
        }
        for (int k = 1; k < len; k++) {
            if (f2(s1, s2, l1, l2, k) && f2(s1, s2, l1 + k, l2 + k, len - k)) {
                return true;
            }
            if (f2(s1, s2, l1, l2 + len - k, k) && f2(s1, s2, l1 + k, l2, len - k)) {
                return true;
            }
        }
        return false;
    }

    bool isScramble3(const string& str1, const string& str2) {
        int n = str1.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, 0)));
        return f3(str1, str2, 0, 0, n, dp);
    }

    bool f3(const string& s1, const string& s2, int l1, int l2, int len, vector<vector<vector<int>>>& dp) {
        if (len == 1) {
            return s1[l1] == s2[l2];
        }
        if (dp[l1][l2][len] != 0) {
            return dp[l1][l2][len] == 1;
        }
        bool ans = false;
        for (int k = 1; k < len; k++) {
            if (f3(s1, s2, l1, l2, k, dp) && f3(s1, s2, l1 + k, l2 + k, len - k, dp)) {
                ans = true;
                break;
            }
            if (f3(s1, s2, l1, l2 + len - k, k, dp) && f3(s1, s2, l1 + k, l2, len - k, dp)) {
                ans = true;
                break;
            }
        }
        dp[l1][l2][len] = ans ? 1 : -1;
        return ans;
    }

    bool isScramble4(const string& str1, const string& str2) {
        int n = str1.length();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));
        for (int l1 = 0; l1 < n; l1++) {
            for (int l2 = 0; l2 < n; l2++) {
                dp[l1][l2][1] = (str1[l1] == str2[l2]);
            }
        }
        for (int len = 2; len <= n; len++) {
            for (int l1 = 0; l1 <= n - len; l1++) {
                for (int l2 = 0; l2 <= n - len; l2++) {
                    for (int k = 1; k < len; k++) {
                        if ((dp[l1][l2][k] && dp[l1 + k][l2 + k][len - k]) ||
                            (dp[l1][l2 + len - k][k] && dp[l1 + k][l2][len - k])) {
                            dp[l1][l2][len] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};
