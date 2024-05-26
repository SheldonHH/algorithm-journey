// setAll功能的哈希表
// 测试链接 : https://www.nowcoder.com/practice/7c4559f138e74ceb9ba57d76fd169967
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过

#include <iostream>
#include <unordered_map>
using namespace std;

// 要求setall, put, get全部是O(1)
// 加盖时间戳技巧 https://www.bilibili.com/opus/935769942432677888?spm_id_from=333.999.0.0
// 别修改里面的值，而是
class Main {
public:
    static unordered_map<int, pair<int, int>> map;
    static int setAllValue; // 0
    static int setAllTime;  // -1
    static int cnt; //每进入一个值就++

    static void put(int k, int v) {
        if (map.find(k) != map.end()) {
            map[k] = {v, cnt++};
        } else {
            map[k] = {v, cnt++};
        }
    }

    static void setAll(int v) {
        setAllValue = v;
        setAllTime = cnt++;
    }

    static int get(int k) {
        if (map.find(k) == map.end()) {
            return -1;
        }
        auto value = map[k];
        // setAll时间比他更新 https://www.bilibili.com/opus/935770956063834136?spm_id_from=333.999.0.0
        // 看是拿setAllValue的值，还是自身的值，用时间戳技术
        if (value.second > setAllTime) {
            return value.first;
        } else {
            return setAllValue;
        }
    }

    static void process() {
        int n, op, a, b;
        cin >> n; // 读取操作数量 n
        for (int i = 0; i < n; i++) { // 遍历每个操作
            cin >> op; // 读取操作码 op
            if (op == 1) {
                cin >> a >> b; // 读取参数 a 和 b
                put(a, b); // 调用 put 方法
            } else if (op == 2) {
                cin >> a; // 读取参数 a
                cout << get(a) << endl; // 输出 get 方法的结果
            } else {
                cin >> a; // 读取参数 a
                setAll(a); // 调用 setAll 方法
            }
        }
    }
}; //在 C++ 中，类定义的末尾必须加上分号 ;。
// 这是因为在 C++ 中，类定义被视为声明语句的一部分，所有声明语句必须以分号结尾。

// 定义 Main 类的静态成员变量
unordered_map<int, pair<int, int>> Main::map; // 定义 map，用于存储键值对及其修改时间
int Main::setAllValue = 0; // setAll 操作的值
int Main::setAllTime = -1; // setAll 操作的时间戳
int Main::cnt = 0; // 计数器，用于记录操作时间



//在 Java 中，main 函数必须放在一个类的内部，这是因为 Java 是一种纯面向对象的语言，
// 在 C++ 中，main 函数是在类之外定义的。C++ 支持面向对象编程，但它不是纯面向对象的语言，因此允许在全局作用域中定义函数。
// 是的，在 C++ 中，main 函数不应该放在类的内部。main 函数是程序的入口点，它是在全局作用域中定义的，而不是类的成员。
int main() {
    ios::sync_with_stdio(false); // 关闭 C++ 标准库和 C 标准库的同步，以加快输入输出速度
    cin.tie(nullptr); // 解开 cin 和 cout 之间的绑定关系
    cout.tie(nullptr); // 解开 cout 和 cin 之间的绑定关系
    Main::process(); // 调用 Main 类的 process 方法
    return 0; // 返回 0，表示程序正常结束
}

// 在 C++ 中，标准输入流 cin 和标准输出流 cout 默认是绑定在一起的。这意味着在每次使用 cin 进行输入操作之前，cout 会自动刷新其缓冲区。这种机制可以确保所有输出在等待输入之前都能正确地显示在屏幕上。
// 但是，在某些情况下，这种自动刷新机制可能会降低程序的运行效率，特别是在进行大量输入输出操作时。
// cin.tie(nullptr); 和 cout.tie(nullptr); 分别用来解除 cin 和 cout 之间的绑定关系。这样可以避免 cin 在每次输入前都强制刷新 cout 的缓冲区，从而提高输入输出操作的效率。
// nullptr 是一个空指针，表示不再将 cin 和 cout 绑定到其他流上。
// 通过解除 cin 和 cout 的绑定，输入输出操作不再互相影响，可以提高性能，但需要注意：

// 在解除绑定后，如果程序中混合使用了 cin 和 cout，可能会出现输出显示不及时的问题，因此在使用这两个流时要特别小心，确保输出是及时和正确的。