#include <vector>
#include <unordered_map>
#include <string>

// 使用固定大小数组实现的Trie树节点
// 用类描述实现前缀树。不推荐！
// 测试链接 : https://leetcode.cn/problems/implement-trie-ii-prefix-tree/
class Trie1 {
    struct TrieNode {
        int pass = 0;
        int end = 0;
        std::vector<TrieNode*> nexts; 

        TrieNode() : nexts(26, nullptr) {} // 初始化26个字母的节点数组
    };

    TrieNode* root;

public:
    Trie1() {
        root = new TrieNode(); // 初始化根节点
    }

    void insert(const std::string& word) {
        TrieNode* node = root;
        node->pass++;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->nexts[index] == nullptr) {
                node->nexts[index] = new TrieNode(); // 创建新节点
            }
            node = node->nexts[index];
            node->pass++;
        }
        node->end++;
    }

    // 之前word插入过前缀树，删掉一次
    // 之前的word没有出现过前缀树，什么也不做
    void erase(const std::string& word) {
        if (countWordsEqualTo(word) > 0) { // 出现次数大于0，
            TrieNode* node = root;
            node->pass--; //删除的时候--
            for (char ch : word) {
                int index = ch - 'a';
                TrieNode* next = node->nexts[index];
                if (--next->pass == 0) {
                    delete next; // 删除节点
                    node->nexts[index] = nullptr;
                    return;
                }
                node = next;
            }
            node->end--;
        }
    }

    int countWordsEqualTo(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->nexts[index] == nullptr) {
                return 0; // 未找到单词
            }
            node = node->nexts[index];
        }
        return node->end;
    }


    // 前缀树里面，有多少个单词以pre做前缀
    int countWordsStartingWith(const std::string& pre) {
        TrieNode* node = root;
        for (char ch : pre) {
            int index = ch - 'a';
            if (node->nexts[index] == nullptr) {
                return 0; // 未找到前缀
            }
            node = node->nexts[index];
        }
        return node->pass;
    }
};

// 使用哈希表实现的Trie树节点
class Trie2 {
    struct TrieNode {
        int pass = 0;
        int end = 0;
        std::unordered_map<char, TrieNode*> nexts;

        TrieNode() {}
    };

    TrieNode* root;

public:
    Trie2() {
        root = new TrieNode(); // 初始化根节点
    }

    void insert(const std::string& word) {
        TrieNode* node = root;
        node->pass++;
        for (char ch : word) {
            if (node->nexts.find(ch) == node->nexts.end()) {
                node->nexts[ch] = new TrieNode(); // 创建新节点
            }
            node = node->nexts[ch];
            node->pass++;
        }
        node->end++;
    }

    void erase(const std::string& word) {
        if (countWordsEqualTo(word) > 0) {
            TrieNode* node = root;
            node->pass--;
            for (char ch : word) {
                TrieNode* next = node->nexts[ch];
                if (--next->pass == 0) {
                    delete next; // 删除节点
                    node->nexts.erase(ch);
                    return;
                }
                node = next;
            }
            node->end--;
        }
    }

    int countWordsEqualTo(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->nexts.find(ch) == node->nexts.end()) {
                return 0; // 未找到单词
            }
            node = node->nexts[ch];
        }
        return node->end;
    }

    int countWordsStartingWith(const std::string& pre) {
        TrieNode* node = root;
        for (char ch : pre) {
            if (node->nexts.find(ch) == node->nexts.end()) {
                return 0; // 未找到前缀
            }
            node = node->nexts[ch];
        }
        return node->pass;
    }
};
