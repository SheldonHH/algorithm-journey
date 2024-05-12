# A positive integer is magical if it can be divided by either a or b.
# Given three integers n, a, and b, return the nth magical number.
# Since the answer might be very large, return the answer modulo 10^9 + 7.
# Test link: https://leetcode-cn.com/problems/nth-magical-number/
class NthMagicalNumber:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        def gcd(x, y):
            return x if y == 0 else gcd(y, x % y)

        def lcm(x, y):
            return x * y // gcd(x, y)

        lcmVal = lcm(a, b)
        l, r, ans = 0, n * min(a, b), 0
        
        while l <= r:
            m = (l + r) // 2
            if m // a + m // b - m // lcmVal >= n:
                ans = m
                r = m - 1
            else:
                l = m + 1
                
        return ans % 1000000007
