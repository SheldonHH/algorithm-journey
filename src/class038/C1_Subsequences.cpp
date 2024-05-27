#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

// 字符串的全部子序列
// 子序列本身是可以有重复的，只是这个题目要求去重

void f1(const vector<char>& s, size_t i, string& path, unordered_set<string>& set) {
    if (i == s.size()) {
        set.insert(path);
    } else {
        path.push_back(s[i]); // 加到路径中去
        f1(s, i + 1, path, set);
        path.pop_back(); // 从路径中移除
        f1(s, i + 1, path, set);
    }
}

vector<string> generate_permutation(const string& str) {
    vector<char> s(str.begin(), str.end());
    unordered_set<string> set;
    string path;
    f1(s, 0, path, set);
    return vector<string>(set.begin(), set.end());
}

void f2(const vector<char>& s, size_t i, vector<char>& path, size_t size, unordered_set<string>& set) {
    if (i == s.size()) {
        set.insert(string(path.begin(), path.begin() + size));
    } else {
        path[size] = s[i];
        f2(s, i + 1, path, size + 1, set);
        f2(s, i + 1, path, size, set);
    }
}

vector<string> generate_permutation2(const string& str) {
    vector<char> s(str.begin(), str.end());
    unordered_set<string> set;
    vector<char> path(s.size());
    f2(s, 0, path, 0, set);
    return vector<string>(set.begin(), set.end());
}

int main() {
    string input = "abc";
    vector<string> result = generate_permutation(input);
    for (const auto& s : result) {
        cout << s << endl;
    }

    vector<string> result2 = generate_permutation2(input);
    for (const auto& s : result2) {
        cout << s << endl;
    }

    return 0;
}
