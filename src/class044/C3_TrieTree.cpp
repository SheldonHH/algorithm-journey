#include <iostream>
#include <vector>
#include <string>
#include <cstring>  // for memset

using namespace std;

// 使用固定数组实现前缀树，推荐用于固定字符集
class TrieTree {
private:
    static const int MAXN = 150001;
    static const int ALPHABET_SIZE = 26;
    int tree[MAXN][ALPHABET_SIZE];
    int end[MAXN];
    int pass[MAXN];
    int cnt;

public:
    TrieTree() {
        cnt = 1;  // 初始化时节点计数从1开始
        memset(tree, 0, sizeof(tree));
        memset(end, 0, sizeof(end));
        memset(pass, 0, sizeof(pass));
    }

    void insert(const string& word) {
        int cur = 1;
        pass[cur]++;
        for (char ch : word) {
            int path = ch - 'a';
            if (tree[cur][path] == 0) {
                tree[cur][path] = ++cnt;  // 如果路径不存在，创建新节点
            }
            cur = tree[cur][path];
            pass[cur]++;
        }
        end[cur]++;
    }

    int search(const string& word) {
        int cur = 1;
        for (char ch : word) {
            int path = ch - 'a';
            if (tree[cur][path] == 0) {
                return 0;  // 路径不存在，搜索失败
            }
            cur = tree[cur][path];
        }
        return end[cur];
    }

    int prefixNumber(const string& pre) {
        int cur = 1;
        for (char ch : pre) {
            int path = ch - 'a';
            if (tree[cur][path] == 0) {
                return 0;  // 前缀不存在
            }
            cur = tree[cur][path];
        }
        return pass[cur];
    }

    void deleteWord(const string& word) {
        if (search(word) > 0) {  // 先搜索确认单词存在
            int cur = 1;
            for (char ch : word) {
                int path = ch - 'a';
                if (--pass[tree[cur][path]] == 0) {
                    tree[cur][path] = 0;  // 减少引用，若为0，则清空路径
                    return;
                }
                cur = tree[cur][path];
            }
            end[cur]--;
        }
    }

    void clear() {
        for (int i = 1; i <= cnt; ++i) {
            memset(tree[i], 0, sizeof(tree[i]));
            end[i] = 0;
            pass[i] = 0;
        }
    }
};

int main() {
    TrieTree trie;
    string line;
    int m, op;
    string word;

    // 处理输入输出
    while (getline(cin, line)) {
        trie = TrieTree();  // 重新构建Trie树
        m = stoi(line);
        for (int i = 0; i < m; ++i) {
            cin >> op >> word;
            switch (op) {
                case 1:
                    trie.insert(word);
                    break;
                case 2:
                    trie.deleteWord(word);
                    break;
                case 3:
                    cout << (trie.search(word) > 0 ? "YES" : "NO") << endl;
                    break;
                case 4:
                    cout << trie.prefixNumber(word) << endl;
                    break;
            }
        }
        trie.clear();
    }

    return 0;
}
