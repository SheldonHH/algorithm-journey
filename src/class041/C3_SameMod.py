import random

# This class is about the modulo property of addition, subtraction, and multiplication
# It doesn't cover division as division requires inverse modulo, which will be covered later
class SameMod:

    # For testing purposes
    @staticmethod
    def random():
        return random.randint(0, 2**63-1)

    # Calculate ((a + b) * (c - d) + (a * c - b * d)) % mod with non-negative result
    @staticmethod
    def f1(a, b, c, d, mod):
        o1 = a % mod
        o2 = b % mod
        o3 = c % mod
        o4 = d % mod
        o5 = (o1 + o2) % mod
        o6 = (o3 - o4 + mod) % mod
        o7 = (o1 * o3) % mod
        o8 = (o2 * o4) % mod
        o9 = (o5 * o6) % mod
        o10 = (o7 - o8 + mod) % mod
        return (o9 + o10) % mod

    @staticmethod
    def f2(a, b, c, d, mod):
        # Same logic but with different calculation style
        o1, o2, o3, o4 = a % mod, b % mod, c % mod, d % mod
        o5 = (o1 + o2) % mod
        o6 = (o3 - o4 + mod) % mod
        o7 = (o1 * o3) % mod
        o8 = (o2 * o4) % mod
        o9 = (o5 * o6) % mod
        o10 = (o7 - o8 + mod) % mod
        return (o9 + o10) % mod

    @staticmethod
    def main():
        print("Testing starts")
        testTime = 100000
        mod = 1000000007
        for _ in range(testTime):
            a, b, c, d = SameMod.random(), SameMod.random(), SameMod.random(), SameMod.random()
            if SameMod.f1(a, b, c, d, mod) != SameMod.f2(a, b, c, d, mod):
                print("Error!")
        print("Testing ends")

        print("===")
        a, b, c, d = SameMod.random(), SameMod.random(), SameMod.random(), SameMod.random()
        print(f"a: {a}")
        print(f"b: {b}")
        print(f"c: {c}")
        print(f"d: {d}")
        print("===")
        print(f"f1: {SameMod.f1(a, b, c, d, mod)}")
        print(f"f2: {SameMod.f2(a, b, c, d, mod)}")

if __name__ == '__main__':
    SameMod.main()
