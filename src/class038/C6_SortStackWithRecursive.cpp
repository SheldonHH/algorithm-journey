#include <iostream>
#include <stack>
#include <algorithm> // For max

// 使用递归函数对栈进行排序
// 只使用栈的push、pop、empty三个方法以及递归函数，禁用其他容器和数组
class Code06_SortStackWithRecursive {
public:
    // 主函数，对栈进行排序
    static void sort(stack<int>& s) {
        int depth = getDepth(s);
        while (depth > 0) {
            int max = getMax(s, depth);
            int count = getCount(s, depth, max);
            sinkMax(s, depth, max, count);
            depth -= count;
        }
    }

private:
    // 计算栈的深度，不改变栈的内容
    static int getDepth(stack<int>& s) {
        if (s.empty()) {
            return 0;
        }
        int val = s.top();
        s.pop();
        int depth = 1 + getDepth(s);
        s.push(val);
        return depth;
    }

    // 寻找栈中深度为depth的最大值
    static int getMax(stack<int>& s, int depth) {
        if (depth == 0) {
            return INT_MIN;
        }
        int val = s.top();
        s.pop();
        int restMax = getMax(s, depth - 1);
        int maxVal = max(val, restMax);
        s.push(val);
        return maxVal;
    }

    // 计算最大值max在栈中出现的次数
    static int getCount(stack<int>& s, int depth, int max) {
        if (depth == 0) {
            return 0;
        }
        int val = s.top();
        s.pop();
        int restCount = getCount(s, depth - 1, max);
        int count = restCount + (val == max ? 1 : 0);
        s.push(val);
        return count;
    }

    // 将最大值沉到栈底
    static void sinkMax(stack<int>& s, int depth, int max, int k) {
        if (depth == 0) {
            for (int i = 0; i < k; i++) {
                s.push(max);
            }
        } else {
            int val = s.top();
            s.pop();
            sinkMax(s, depth - 1, max, k);
            if (val != max) {
                s.push(val);
            }
        }
    }
};

// 测试程序
int main() {
    stack<int> test;
    test.push(1);
    test.push(5);
    test.push(4);
    test.push(5);
    test.push(3);
    test.push(2);
    test.push(3);
    test.push(1);
    test.push(4);
    test.push(2);
    Code06_SortStackWithRecursive::sort(test);
    while (!test.empty()) {
        cout << test.top() << endl;
        test.pop();
    }

    // 随机测试
    cout << "测试开始" << endl;
    for (int i = 0; i < 20000; i++) {
        stack<int> stack;
        for (int j = 0; j < 20; j++) {
            stack.push(rand() % 20);
        }
        Code06_SortStackWithRecursive::sort(stack);
        bool sorted = true;
        int last = INT_MAX;
        while (!stack.empty()) {
            if (last < stack.top()) {
                sorted = false;
                break;
            }
            last = stack.top();
            stack.pop();
        }
        if (!sorted) {
            cout << "出错了!" << endl;
            break;
        }
    }
    cout << "测试结束" << endl;

    return 0;
}
