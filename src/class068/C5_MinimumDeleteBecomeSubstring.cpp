#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Code05_MinimumDeleteBecomeSubstring {
public:
    // 暴力方法
    // 为了验证
    static int minDelete1(const string& s1, const string& s2) {
        vector<string> list;
        generateSubsequences(s1, 0, "", list);
        // 排序 : 长度大的子序列先考虑
        sort(list.begin(), list.end(), [](const string& a, const string& b) {
            return b.length() > a.length();
        });
        for (const string& str : list) {
            if (s2.find(str) != string::npos) {
                // 检查s2中，是否包含当前的s1子序列str
                return s1.length() - str.length();
            }
        }
        return s1.length();
    }

    // 生成s1字符串的所有子序列串
    static void generateSubsequences(const string& s1, int i, string path, vector<string>& list) {
        if (i == s1.length()) {
            list.push_back(path);
        } else {
            generateSubsequences(s1, i + 1, path, list);
            generateSubsequences(s1, i + 1, path + s1[i], list);
        }
    }

    // 正式方法，动态规划
    static int minDelete2(const string& s1, const string& s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = i;
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j] + 1;
                }
            }
        }
        int ans = INT_MAX;
        for (int j = 0; j <= m; j++) {
            ans = min(ans, dp[n][j]);
        }
        return ans;
    }

    // 为了验证
    static string randomString(int n, int v) {
        string ans(n, ' ');
        for (int i = 0; i < n; i++) {
            ans[i] = 'a' + rand() % v;
        }
        return ans;
    }

    // 对数器
    static void test() {
        int n = 12, v = 3, testTime = 20000;
        cout << "测试开始" << endl;
        srand((unsigned)time(nullptr));
        for (int i = 0; i < testTime; i++) {
            int len1 = rand() % n + 1;
            int len2 = rand() % n + 1;
            string s1 = randomString(len1, v);
            string s2 = randomString(len2, v);
            int ans1 = minDelete1(s1, s2);
            int ans2 = minDelete2(s1, s2);
            if (ans1 != ans2) {
                cout << "出错了!" << endl;
            }
        }
        cout << "测试结束" << endl;
    }
};

int main() {
    Code05_MinimumDeleteBecomeSubstring::test();
    return 0;
}
