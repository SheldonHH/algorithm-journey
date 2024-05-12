class BasicCalculatorIII:
    where = 0

    @staticmethod
    def calculate(s: str) -> int:
        BasicCalculatorIII.where = 0
        return BasicCalculatorIII._f(s, 0)

    @staticmethod
    def _f(s: str, i: int) -> int:
        cur = 0
        numbers = []
        ops = []
        while i < len(s) and s[i] != ')':
            if '0' <= s[i] <= '9':
                cur = cur * 10 + int(s[i])
                i += 1
            elif s[i] != '(':
                # 遇到了运算符 + - * /
                BasicCalculatorIII._push(numbers, ops, cur, s[i])
                cur = 0
                i += 1
            else:
                # i (.....)
                # 遇到了左括号！
                cur = BasicCalculatorIII._f(s, i + 1)
                i = BasicCalculatorIII.where + 1
        BasicCalculatorIII._push(numbers, ops, cur, '+')
        BasicCalculatorIII.where = i
        return BasicCalculatorIII._compute(numbers, ops)

    @staticmethod
    def _push(numbers, ops, cur, op):
        if not ops or ops[-1] == '+' or ops[-1] == '-':
            numbers.append(cur)
            ops.append(op)
        else:
            top_number = numbers.pop()
            top_op = ops.pop()
            if top_op == '*':
                numbers.append(top_number * cur)
            else:
                numbers.append(top_number // cur)
            ops.append(op)

    @staticmethod
    def _compute(numbers, ops):
        ans = numbers[0]
        for i in range(1, len(numbers)):
            if ops[i - 1] == '+':
                ans += numbers[i]
            else:
                ans -= numbers[i]
        return ans

# 使用示例
# print(BasicCalculatorIII.calculate("2*(5+5*2)/3+(6/2+8)"))
