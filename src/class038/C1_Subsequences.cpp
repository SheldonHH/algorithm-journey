#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

// 生成字符串的所有不重复子序列
vector<string> generatePermutation1(const string& str) {
    auto f1 = [](const vector<char>& s, int i, string& path, unordered_set<string>& set) {
        if (i == s.size()) {
            set.insert(path);
        } else {
            path.push_back(s[i]); // 加入路径
            f1(s, i + 1, path, set);
            path.pop_back(); // 移除路径
            f1(s, i + 1, path, set);
        }
    };

    vector<char> s(str.begin(), str.end());
    unordered_set<string> set;
    string path;
    f1(s, 0, path, set);

    return vector<string>(set.begin(), set.end());
}

// 使用固定大小的char数组来生成子序列
vector<string> generatePermutation2(const string& str) {
    auto f2 = [](const vector<char>& s, int i, vector<char>& path, int size, unordered_set<string>& set) {
        if (i == s.size()) {
            set.insert(string(path.begin(), path.begin() + size));
        } else {
            path[size] = s[i];
            f2(s, i + 1, path, size + 1, set);
            f2(s, i + 1, path, size, set);
        }
    };

    vector<char> s(str.begin(), str.end());
    unordered_set<string> set;
    vector<char> path(s.size());
    f2(s, 0, path, 0, set);

    return vector<string>(set.begin(), set.end());
}

int main() {
    // 测试
    string str = "abc";
    auto result1 = generatePermutation1(str);
    auto result2 = generatePermutation2(str);

    cout << "方法一生成的子序列：" << endl;
    for (const auto& seq : result1) {
        cout << seq << endl;
    }

    cout << "方法二生成的子序列：" << endl;
    for (const auto& seq : result2) {
        cout << seq << endl;
    }

    return 0;
}
