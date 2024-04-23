#include <vector>
#include <iostream>

class FibonacciNumber {
public:
    static int fib1(int n) {
        return f1(n);
    }

    static int f1(int i) {
        if (i == 0) return 0;
        if (i == 1) return 1;
        return f1(i - 1) + f1(i - 2);
    }

    static int fib2(int n) {
        std::vector<int> dp(n + 1, -1);
        return f2(n, dp);
    }

    static int f2(int i, std::vector<int>& dp) {
        if (i == 0) return 0;
        if (i == 1) return 1;
        if (dp[i] != -1) return dp[i];
        dp[i] = f2(i - 1, dp) + f2(i - 2, dp);
        return dp[i];
    }

    static int fib3(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        std::vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    static int fib4(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int lastLast = 0, last = 1, cur;
        for (int i = 2; i <= n; i++) {
            cur = lastLast + last;
            lastLast = last;
            last = cur;
        }
        return last;
    }
};

int main() {
    // Test the methods
    std::cout << "fib1(10) = " << FibonacciNumber::fib1(10) << std::endl;
    std::cout << "fib2(10) = " << FibonacciNumber::fib2(10) << std::endl;
    std::cout << "fib3(10) = " << FibonacciNumber::fib3(10) << std::endl;
    std::cout << "fib4(10) = " << FibonacciNumber::fib4(10) << std::endl;
    return 0;
}
