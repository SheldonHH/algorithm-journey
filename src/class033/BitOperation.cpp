#include <iostream>
#include <limits.h>
#include <cstdlib>
#include <ctime>

class BitOperation {
public:
    static const int MIN = INT_MIN;

    static int divide(int a, int b) {
        if (a == MIN && b == MIN) return 1;
        if (a != MIN && b != MIN) return div(a, b);
        if (b == MIN) return 0;
        if (b == neg(1)) return INT_MAX;
        a = add(a, b > 0 ? b : neg(b));
        int ans = div(a, b);
        int offset = b > 0 ? neg(1) : 1;
        return add(ans, offset);
    }

    static int div(int a, int b) {
        int x = a < 0 ? neg(a) : a;
        int y = b < 0 ? neg(b) : b;
        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            if ((x >> i) >= y) {
                ans |= (1 << i);
                x = minus(x, y << i);
            }
        }
        return (a < 0 ^ b < 0) ? neg(ans) : ans;
    }

    static int add(int a, int b) {
        int ans;
        while (b != 0) {
            ans = a ^ b;
            b = (a & b) << 1;
            a = ans;
        }
        return ans;
    }

    static int minus(int a, int b) {
        return add(a, neg(b));
    }

    static int neg(int n) {
        return add(~n, 1);
    }

    static int multiply(int a, int b) {
        int ans = 0;
        while (b != 0) {
            if (b & 1) ans = add(ans, a);
            a <<= 1;
            b >>= 1;
        }
        return ans;
    }
};

class Validator {
public:
    static int random_input() {
        return rand() - (RAND_MAX / 2);
    }

    static int add_reference(int a, int b) {
        return a + b;
    }

    static void test_add() {
        srand(time(0));
        for (int i = 0; i < 10000; i++) {
            int a = random_input();
            int b = random_input();
            int expected = add_reference(a, b);
            int result = BitOperation::add(a, b);
            if (expected != result) {
                std::cout << "Failed for " << a << " + " << b << ". Expected " << expected << ", but got " << result << std::endl;
                return;
            }
        }
        std::cout << "All tests passed!" << std::endl;
    }
};

int main() {
    Validator::test_add();
    return 0;
}
