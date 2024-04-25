#include <vector>
#include <algorithm>
#include <iostream>

int nthUglyNumber(int n) {
    /**
     * 返回第n个丑数。丑数定义为只包含质因数2、3或5的正整数。
     */
    std::vector<int> dp(n + 1);  // 创建一个vector来存储丑数，从1到n
    dp[1] = 1;  // 第一个丑数是1
    int i2 = 1, i3 = 1, i5 = 1;  // 用于跟踪2、3、5的倍数位置

    for (int i = 2; i <= n; ++i) {
        int a = dp[i2] * 2;
        int b = dp[i3] * 3;
        int c = dp[i5] * 5;
        int cur = std::min({a, b, c});  // 选择最小值作为下一个丑数

        if (cur == a) {  // 更新对应因子的索引
            i2++;
        }
        if (cur == b) {
            i3++;
        }
        if (cur == c) {
            i5++;
        }

        dp[i] = cur;  // 将选定的丑数存储在dp数组中
    }

    return dp[n];  // 返回第n个丑数
}

int main() {
    std::cout << nthUglyNumber(10) << std::endl;  // 输出第10个丑数
    return 0;
}
