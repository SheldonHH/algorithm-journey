#include <iostream>

namespace std {

// 计算两个数的最大公约数
long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 计算两个数的最小公倍数
long lcm(long a, long b) {
    return a / gcd(a, b) * b;
}

// 给定三个整数 n, a, b，返回第 n 个神奇的数字。答案对 10^9 + 7 取模
int nthMagicalNumber(int n, int a, int b) {
    long lcm_value = lcm(a, b);
    long ans = 0;
    long l = 0;
    long r = (long)n * std::min(a, b);

    while (l <= r) {
        long m = (l + r) / 2;
        // 计算区间1到m内，能被a或b整除的数字数量
        if (m / a + m / b - m / lcm_value >= n) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return (int)(ans % 1000000007);
}

} // namespace std

// 示例用于演示功能，可以根据需要修改
int main() {
    int n = 5, a = 2, b = 3;
    std::cout << "第 " << n << " 个神奇数字是: " << std::nthMagicalNumber(n, a, b) << std::endl;
    return 0;
}
