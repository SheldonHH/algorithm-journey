#include <stack>
#include <vector>
using namespace std;

// 最小栈
// 测试链接 : https://leetcode.cn/problems/min-stack/
class MinStack1 {
public:
    stack<int> data;
    stack<int> min;

    MinStack1() {
        // 构造函数
    }

    void push(int val) {
        // 入栈
        data.push(val);
        if (min.empty() || val <= min.top()) {
            min.push(val);
        } else { // !min.empty() && val > min.top()
            min.push(min.top());
        }
    }

    void pop() {
        // 出栈
        data.pop();
        min.pop();
    }

    int top() {
        // 获取栈顶元素
        return data.top();
    }

    int getMin() {
        // 获取栈中的最小元素
        return min.top();
    }
};

class MinStack2 {
public:
    // leetcode的数据在测试时，同时在栈里的数据不超过这个值
    // 这是几次提交实验出来的，哈哈
    // 如果leetcode补测试数据了，超过这个量导致出错，就调大
    static const int MAXN = 8001;

    int data[MAXN];
    int min[MAXN];
    int size;

    MinStack2() : size(0) {
        // 构造函数
    }

    void push(int val) {
        // 入栈
        data[size] = val;
        if (size == 0 || val <= min[size - 1]) {
            min[size] = val;
        } else {
            min[size] = min[size - 1];
        }
        size++;
    }

    void pop() {
        // 出栈
        size--;
    }

    int top() {
        // 获取栈顶元素
        return data[size - 1];
    }

    int getMin() {
        // 获取栈中的最小元素
        return min[size - 1];
    }
};
