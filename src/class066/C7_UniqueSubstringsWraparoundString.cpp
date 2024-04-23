#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 环绕字符串中唯一的子字符串
int findSubstringInWraproundString(const string& str) {
    int n = str.length();
    vector<int> s(n);
    // 将字符转换为从0开始的索引，即 'a' -> 0, 'b' -> 1, ..., 'z' -> 25
    for (int i = 0; i < n; i++) {
        s[i] = str[i] - 'a';
    }

    vector<int> dp(26, 0); // dp[i] 表示以字符 'a'+i 结尾的最长子字符串的长度
    dp[s[0]] = 1;
    int cur, pre, len = 1; // cur当前字符索引，pre前一个字符索引，len当前有效长度

    for (int i = 1; i < n; i++) {
        cur = s[i];
        pre = s[i - 1];
        // 检查当前字符是否能延续前一个字符形成环绕子字符串
        if ((pre == 25 && cur == 0) || pre + 1 == cur) {
            len++; // 延伸长度
        } else {
            len = 1; // 重新开始
        }
        dp[cur] = max(dp[cur], len); // 更新以当前字符结尾的最大长度
    }

    int ans = 0;
    // 统计所有不同子字符串的长度之和
    for (int i = 0; i < 26; i++) {
        ans += dp[i];
    }
    return ans;
}

int main() {
    string s = "zab";
    cout << "Unique substrings in wraparound string: " << findSubstringInWraproundString(s) << endl;
    return 0;
}
