#include <queue>
#include <stack>
#include <vector>

// 使用 C++ 的内部实现，内部通常使用双向链表
class Queue1 {
public:
    std::queue<int> queue;

    bool isEmpty() {
        return queue.empty();
    }

    void offer(int num) {
        queue.push(num);
    }

    int poll() {
        int front = queue.front();
        queue.pop();
        return front;
    }

    int peek() {
        return queue.front();
    }

    int size() {
        return queue.size();
    }
};

// 使用静态数组来实现队列
class Queue2 {
private:
    std::vector<int> queue;
    int l, r, capacity;

public:
    Queue2(int n) : queue(std::vector<int>(n)), l(0), r(0), capacity(n) {}

    bool isEmpty() {
        return l == r;
    }

    void offer(int num) {
        queue[r] = num;
        r = (r + 1) % capacity;
    }

    int poll() {
        int val = queue[l];
        l = (l + 1) % capacity;
        return val;
    }

    int head() {
        return queue[l];
    }

    int tail() {
        return queue[(r - 1 + capacity) % capacity];
    }

    int size() {
        return (r - l + capacity) % capacity;
    }
};

// 使用 C++ 内部的 stack 实现
class Stack1 {
private:
    std::stack<int> stack;

public:
    bool isEmpty() {
        return stack.empty();
    }

    void push(int num) {
        stack.push(num);
    }

    int pop() {
        int top = stack.top();
        stack.pop();
        return top;
    }

    int peek() {
        return stack.top();
    }

    int size() {
        return stack.size();
    }
};

// 使用静态数组来实现栈
class Stack2 {
private:
    std::vector<int> stack;
    int top;

public:
    Stack2(int n) : stack(std::vector<int>(n)), top(0) {}

    bool isEmpty() {
        return top == 0;
    }

    void push(int num) {
        stack[top++] = num;
    }

    int pop() {
        return stack[--top];
    }

    int peek() {
        return stack[top - 1];
    }

    int size() {
        return top;
    }
};

// 实现循环队列
class MyCircularQueue {
private:
    std::vector<int> queue;
    int l, r, size, limit;

public:
    MyCircularQueue(int k) : queue(std::vector<int>(k)), l(0), r(0), size(0), limit(k) {}

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        } else {
            queue[r] = value;
            r = (r + 1) % limit;
            size++;
            return true;
        }
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        } else {
            l = (l + 1) % limit;
            size--;
            return true;
        }
    }

    int Front() {
        return isEmpty() ? -1 : queue[l];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        } else {
            int last = r == 0 ? limit - 1 : r - 1;
            return queue[last];
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == limit;
    }
};
