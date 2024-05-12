#include <string>
#include <map>
using namespace std;

// 含有嵌套的分子式求原子数量
// 测试链接 : https://leetcode.cn/problems/number-of-atoms/
class Code03_NumberOfAtoms {
public:
    static int where;

    // 主函数
    static string countOfAtoms(string str) {
        where = 0;
        map<string, int> map = f(str, 0);
        string ans;
        for (auto &entry : map) {
            ans += entry.first;
            int cnt = entry.second;
            if (cnt > 1) {
                ans += to_string(cnt);
            }
        }
        return ans;
    }

    // s[i....]开始计算，遇到字符串终止 或者 遇到 ')' 停止
    // 返回 : 自己负责的这一段字符串的结果，有序表！
    // 返回之间，更新全局变量where，为了上游函数知道从哪继续！
    static map<string, int> f(const string &s, int i) {
        map<string, int> ans;
        string name;
        map<string, int> pre;
        int cnt = 0;
        while (i < s.length() && s[i] != ')') {
            if ((s[i] >= 'A' && s[i] <= 'Z') || s[i] == '(') {
                fill(ans, name, pre, cnt);
                name.clear();
                pre.clear();
                cnt = 0;
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    name += s[i++];
                } else { // 遇到 '('
                    pre = f(s, i + 1);
                    i = where + 1;
                }
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                name += s[i++];
            } else {
                cnt = cnt * 10 + s[i++] - '0';
            }
        }
        fill(ans, name, pre, cnt);
        where = i;
        return ans;
    }

    // 将收集到的数据填充到总表中
    static void fill(map<string, int> &ans, string &name, map<string, int> &pre, int cnt) {
        if (!name.empty() || !pre.empty()) {
            cnt = cnt == 0 ? 1 : cnt;
            if (!name.empty()) {
                ans[name] += cnt;
            } else {
                for (auto &entry : pre) {
                    ans[entry.first] += entry.second * cnt;
                }
            }
        }
    }
};

int Code03_NumberOfAtoms::where = 0;
