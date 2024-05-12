#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 二叉树节点的定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 如果测试数据量增大，修改此值
const int MAXN = 3001;

TreeNode* nq[MAXN];  // 节点队列
int iq[MAXN];         // 索引队列
int l, r;

// 使用每次处理一层的优化 BFS 来计算二叉树的最大宽度
int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    int ans = 1;
    l = 0;
    r = 0;
    nq[r] = root;
    iq[r++] = 1;
    while (l < r) {
        int size = r - l;
        // 计算当前层的宽度
        ans = max(ans, iq[r - 1] - iq[l] + 1);
        for (int i = 0; i < size; ++i) {
            TreeNode* node = nq[l];
            int id = iq[l++];
            if (node->left) {
                nq[r] = node->left;
                iq[r++] = id * 2;
            }
            if (node->right) {
                nq[r] = node->right;
                iq[r++] = id * 2 + 1;
            }
        }
    }
    return ans;
}

// 注意: 测试时，需要构建相应的二叉树结构来进行测试
