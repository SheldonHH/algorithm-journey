#include <iostream>
#include <random>

// This class is about the modulo property of addition, subtraction, and multiplication
// It doesn't cover division as division requires inverse modulo, which will be covered later
class SameMod {
public:
    // For testing purposes
    static long long random() {
        std::random_device rd;
        std::mt19937_64 eng(rd());
        std::uniform_int_distribution<long long> distr;
        return distr(eng);
    }

    // Calculate ((a + b) * (c - d) + (a * c - b * d)) % mod with non-negative result
    static int f1(long long a, long long b, long long c, long long d, int mod) {
        long long o1 = a % mod;
        long long o2 = b % mod;
        long long o3 = c % mod;
        long long o4 = d % mod;
        long long o5 = (o1 + o2) % mod;
        long long o6 = (o3 - o4 + mod) % mod;
        long long o7 = (o1 * o3) % mod;
        long long o8 = (o2 * o4) % mod;
        long long o9 = (o5 * o6) % mod;
        long long o10 = (o7 - o8 + mod) % mod;
        return (int)((o9 + o10) % mod);
    }

    static void test() {
        std::cout << "Testing starts" << std::endl;
        int testTime = 100000;
        int mod = 1000000007;
        for (int i = 0; i < testTime; ++i) {
            long long a = random();
            long long b = random();
            long long c = random();
            long long d = random();
            if (f1(a, b, c, d, mod) != f1(a, b, c, d, mod)) {
                std::cout << "Error!" << std::endl;
            }
        }
        std::cout << "Testing ends" << std::endl;

        std::cout << "===" << std::endl;
        long long a = random();
        long long b = random();
        long long c = random();
        long long d = random();
        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
        std::cout << "c: " << c << std::endl;
        std::cout << "d: " << d << std::endl;
        std::cout << "===" << std::endl;
        std::cout << "f1: " << f1(a, b, c, d, mod) << std::endl;
    }
};

int main() {
    SameMod::test();
    return 0;
}
