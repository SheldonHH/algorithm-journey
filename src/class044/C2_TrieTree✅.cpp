#include <iostream>
#include <vector>
#include <string>
#include <cstring>  // for memset
#include <sstream>  // for string stream processing

using namespace std;


// https://www.nowcoder.com/practice/7f8a8553ddbf4eaab749ec988726702b


class TrieTree {
private:
    static const int MAXN = 150001;
    static const int ALPHABET_SIZE = 26;
    int tree[MAXN][ALPHABET_SIZE];
    int end[MAXN];
    int pass[MAXN];
    int cnt;

public:
    TrieTree() : cnt(1) {  // Initialization in constructor
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
                tree[cur][path] = ++cnt;
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
                return 0;
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
                return 0;
            }
            cur = tree[cur][path];
        }
        return pass[cur];
    }

    void deleteWord(const string& word) {
        if (search(word) > 0) {
            int cur = 1;
            for (char ch : word) {
                int path = ch - 'a';
                if (--pass[tree[cur][path]] == 0) {
                    tree[cur][path] = 0;
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

    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        if (!(ss >> m)) {
            cerr << "Error: Invalid number of operations." << endl;
            continue;
        }

        trie = TrieTree();  // Reset the Trie
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover newline
    }
    return 0;
}
