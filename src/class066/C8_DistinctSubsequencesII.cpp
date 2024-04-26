#include <iostream>
#include <string>
#include <vector>

// 功能：计算字符串 s 的不同非空子序列的个数
// 参数：字符串 s
// 返回值：子序列个数对 10^9 + 7 取余的结果
int distinctSubseqII(const std::string& s) {
    const int mod = 1000000007;
    std::vector<int> cnt(26, 0);  // 存储每个字符最新贡献的子序列数
    int all = 1;  // 初始化为 1，代表空集的子序列
    for (char x : s) {
        int newAdd = (all - cnt[x - 'a'] + mod) % mod;  // 新增加的子序列数量
        cnt[x - 'a'] = (cnt[x - 'a'] + newAdd) % mod;  // 更新当前字符的贡献
        all = (all + newAdd) % mod;  // 更新所有子序列的总数
    }
    return (all - 1 + mod) % mod;  // 减去空集的子序列，并取模
}

int main() {
    std::string s = "abcde";
    std::cout << "Number of distinct subsequences: " << distinctSubseqII(s) << std::endl;
    return 0;
}
