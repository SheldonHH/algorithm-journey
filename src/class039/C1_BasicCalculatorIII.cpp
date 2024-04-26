#include <vector>
#include <string>

using namespace std;

// 含有嵌套的表达式求值
// 测试链接 : https://leetcode.cn/problems/basic-calculator-iii/
class BasicCalculatorIII {

public:
    static int calculate(const string& str) {
        where = 0;
        return f(str, 0);
    }

private:
    static int where;

    // s[i....]开始计算，遇到字符串终止 或者 遇到')'停止
    // 返回：自己负责的这一段，计算的结果
    // 返回之间，更新全局变量where，为了上游函数知道从哪继续！
    static int f(const string& s, int i) {
        int cur = 0;
        vector<int> numbers;
        vector<char> ops;
        while (i < s.size() && s[i] != ')') {
            if (s[i] >= '0' && s[i] <= '9') {
                cur = cur * 10 + s[i++] - '0';
            } else if (s[i] != '(') {
                // 遇到了运算符 + - * /
                push(numbers, ops, cur, s[i++]);
                cur = 0;
            } else {
                // i (.....)
                // 遇到了左括号！
                cur = f(s, i + 1);
                i = where + 1;
            }
        }
        push(numbers, ops, cur, '+');
        where = i;
        return compute(numbers, ops);
    }

    static void push(vector<int>& numbers, vector<char>& ops, int cur, char op) {
        int n = numbers.size();
        if (n == 0 || ops.back() == '+' || ops.back() == '-') {
            numbers.push_back(cur);
            ops.push_back(op);
        } else {
            int topNumber = numbers.back();
            char topOp = ops.back();
            if (topOp == '*') {
                numbers.back() = topNumber * cur;
            } else {
                numbers.back() = topNumber / cur;
            }
            ops.back() = op;
        }
    }

    static int compute(const vector<int>& numbers, const vector<char>& ops) {
        int ans = numbers[0];
        for (size_t i = 1; i < numbers.size(); i++) {
            ans += ops[i - 1] == '+' ? numbers[i] : -numbers[i];
        }
        return ans;
    }

};

// 全局变量where的定义
int BasicCalculatorIII::where = 0;
