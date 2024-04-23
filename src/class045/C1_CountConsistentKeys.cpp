#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

// 预定义最大节点数
const int MAXN = 2000001;
int tree[MAXN][12];  // Trie 树结构
int pass[MAXN];      // 统计通过当前节点的次数
int cnt;             // 当前Trie树使用的节点数

// 初始化Trie树
void build() {
    cnt = 1;  // 从1开始计数，0通常留给根节点
    memset(tree, 0, sizeof(tree));
    memset(pass, 0, sizeof(pass));
}

// 根据字符获取路径索引
int path(char cha) {
    if (cha == '#') {
        return 10;
    } else if (cha == '-') {
        return 11;
    } else {
        return cha - '0';
    }
}

// 向Trie树中插入差分字符串
void insert(const string& word) {
    int cur = 1;
    pass[cur]++;
    for (char ch : word) {
        int p = path(ch);
        if (tree[cur][p] == 0) {
            tree[cur][p] = ++cnt;
        }
        cur = tree[cur][p];
        pass[cur]++;
    }
}

// 在Trie树中计数满足条件的字符串数量
int count(const string& pre) {
    int cur = 1;
    for (char ch : pre) {
        int p = path(ch);
        if (tree[cur][p] == 0) {
            return 0;
        }
        cur = tree[cur][p];
    }
    return pass[cur];
}

// 清理Trie树
void clear() {
    for (int i = 1; i <= cnt; ++i) {
        memset(tree[i], 0, sizeof(tree[i]));
        pass[i] = 0;
    }
}

// 主函数处理输入和输出
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> b(m), a(n);
    for (int i = 0; i < m; ++i) {
        int len;
        cin >> len;
        b[i].resize(len);
        for (int j = 0; j < len; ++j) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        int len;
        cin >> len;
        a[i].resize(len);
        for (int j = 0; j < len; ++j) {
            cin >> a[i][j];
        }
    }

    build();

    // 为每个密钥a构建差分串并插入Trie
    for (auto& nums : a) {
        string builder;
        for (int i = 1; i < nums.size(); i++) {
            builder.append(to_string(nums[i] - nums[i - 1]) + "#");
        }
        insert(builder);
    }

    vector<int> ans(m);
    // 检查每个密钥b的差分串在Trie中的计数
    for (int i = 0; i < m; i++) {
        string builder;
        for (int j = 1; j < b[i].size(); j++) {
            builder.append(to_string(b[i][j] - b[i][j - 1]) + "#");
        }
        ans[i] = count(builder);
    }

    clear();

    // 输出结果
    for (int num : ans) {
        cout << num << endl;
    }

    return 0;
}
