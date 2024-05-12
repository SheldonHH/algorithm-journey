#include <stack>
#include <queue>

namespace std {

// 使用栈实现队列
class MyQueue {
public:
    stack<int> in, out;

    MyQueue() {
    }

    // 从 in 栈把数据倒入 out 栈
    // 只有当 out 栈为空时，才执行倒入
    void inToOut() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }

    // 添加元素到队尾
    void push(int x) {
        in.push(x);
        inToOut();
    }

    // 弹出队首元素
    int pop() {
        inToOut();
        int x = out.top();
        out.pop();
        return x;
    }

    // 获取队首元素
    int peek() {
        inToOut();
        return out.top();
    }

    // 检查队列是否为空
    bool empty() {
        return in.empty() && out.empty();
    }
};

// 使用队列实现栈
class MyStack {
public:
    queue<int> queue;

    MyStack() {
    }

    // 添加元素到栈顶
    void push(int x) {
        int n = queue.size();
        queue.push(x);
        for (int i = 0; i < n; i++) {
            queue.push(queue.front());
            queue.pop();
        }
    }

    // 弹出栈顶元素
    int pop() {
        int x = queue.front();
        queue.pop();
        return x;
    }

    // 获取栈顶元素
    int top() {
        return queue.front();
    }

    // 检查栈是否为空
    bool empty() {
        return queue.empty();
    }
};

} // namespace std
