import random

class Validator:
    
    @staticmethod
    def random_input():
        return random.randint(-2**31, 2**31 - 1)

    @staticmethod
    def add_reference(a, b):
        return a + b

    @staticmethod
    def test_add():
        for _ in range(30):  # Test 30 times
            a = Validator.random_input()
            b = Validator.random_input()
            expected = Validator.add_reference(a, b)
            result = BitOperation.add(a, b)
            if expected != result:
                print(f"Failed for {a} + {b}. Expected {expected}, but got {result}")
                return
        print("All tests passed!")
class BitOperation:
    
    MIN = -2**31

    @staticmethod
    def divide(a, b):
        if a == BitOperation.MIN and b == BitOperation.MIN:
            return 1
        if a != BitOperation.MIN and b != BitOperation.MIN:
            return BitOperation.div(a, b)
        if b == BitOperation.MIN:
            return 0
        if b == BitOperation.neg(1):
            return 2**31 - 1  # Max int value
        a += b if b > 0 else BitOperation.neg(b)
        ans = BitOperation.div(a, b)
        offset = -1 if b > 0 else 1
        return BitOperation.add(ans, offset)

    @staticmethod
    def div(a, b):
        x = BitOperation.neg(a) if a < 0 else a
        y = BitOperation.neg(b) if b < 0 else b
        ans = 0
        for i in range(30, -1, -1):
            if (x >> i) >= y:
                ans |= (1 << i)
                x = BitOperation.minus(x, y << i)
        return BitOperation.neg(ans) if (a < 0) ^ (b < 0) else ans

    @staticmethod
    def add(a, b):
        while b != 0:
            ans = a ^ b
            b = (a & b) << 1
            a = ans
        return ans

    @staticmethod
    def minus(a, b):
        return BitOperation.add(a, BitOperation.neg(b))

    @staticmethod
    def neg(n):
        return BitOperation.add(~n, 1)

    @staticmethod
    def multiply(a, b):
        ans = 0
        while b != 0:
            if b & 1 != 0:
                ans = BitOperation.add(ans, a)
            a <<= 1
            b >>= 1
        return ans


Validator.test_add()
