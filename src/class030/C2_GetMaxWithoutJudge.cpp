#include <iostream>
#include <climits> // For INT_MIN, INT_MAX

// 使用 std 命名空间
using namespace std;

// 翻转一个整数的最低位，即 0变1，1 变 0
int flip(int n) {
    return n ^ 1; //0　变1；1变0
}

// 返回整数的符号
// 非负数返回 1
// 负数返回 0
int sign(int n) {
    // 利用无符号右移将符号位移到最低位，然后翻转
    return flip((unsigned int)n >> 31);
}

// 使用有溢出风险的方式计算两个数的最大值
int getMax1(int a, int b) {
    int c = a - b;
    int returnA = sign(c);  // c 非负，a 大；c 负，b 大
    int returnB = flip(returnA);
    return a * returnA + b * returnB;
}

// 负数1，非负返回0
// 安全地计算两个数的最大值，无溢出风险
int getMax2(int a, int b) {
    int c = a - b;
    int sa = sign(a);  // a 的符号
    int sb = sign(b);  // b 的符号
    int sc = sign(c);  // c 的符号

    // a 和 b 符号不同则 diffAB 为 1，相同则为 0
    int diffAB = sa ^ sb;
    // a 和 b 符号相同则 sameAB 为 1，不同则为 0
    int sameAB = flip(diffAB);

    // 当 a 和 b 符号不同：a >= 0, b < 0 => returnA = 1; a < 0, b >= 0 => returnA = 0
    // 当 a 和 b 符号相同：取决于 c 的符号
    int returnA = diffAB * sa + sameAB * sc;
    int returnB = flip(returnA);
    return a * returnA + b * returnB;
}

int main() {
    int a = INT_MIN;
    int b = INT_MAX;

    // getMax1 方法可能会因为整数溢出而出错
    cout << "getMax1: " << getMax1(a, b) << endl;

    // getMax2 方法总是能正确处理
    cout << "getMax2: " << getMax2(a, b) << endl;

    return 0;
}
