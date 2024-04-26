#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// 二叉树节点的定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 使用普通 BFS 来进行层序遍历，不推荐此方法
vector<vector<int>> levelOrder1(TreeNode* root) {
    vector<vector<int>> ans;
    if (root != nullptr) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*, int> levels;
        q.push(root);
        levels[root] = 0;
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            int level = levels[cur];
            if (ans.size() == level) {
                ans.emplace_back();
            }
            ans[level].push_back(cur->val);
            if (cur->left != nullptr) {
                q.push(cur->left);
                levels[cur->left] = level + 1;
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
                levels[cur->right] = level + 1;
            }
        }
    }
    return ans;
}

// 如果测试数据量增大，修改此值
const int MAXN = 2001;

TreeNode* queue2[MAXN];
int l, r;

// 使用每次处理一层的优化 BFS 方法进行层序遍历，推荐此方法
vector<vector<int>> levelOrder2(TreeNode* root) {
    vector<vector<int>> ans;
    if (root != nullptr) {
        l = 0;
        r = 0;
        queue2[r++] = root;
        while (l < r) { // 队列中还有节点
            int size = r - l;
            vector<int> list;
            for (int i = 0; i < size; ++i) {
                TreeNode* cur = queue2[l++];
                list.push_back(cur->val);
                if (cur->left != nullptr) {
                    queue2[r++] = cur->left;
                }
                if (cur->right != nullptr) {
                    queue2[r++] = cur->right;
                }
            }
            ans.push_back(list);
        }
    }
    return ans;
}

// 注意: 测试时，主函数中需要构建相应的二叉树结构来进行测试
