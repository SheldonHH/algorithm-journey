#include <iostream>
#include <queue>

using namespace std;

// 验证完全二叉树
// 测试链接 : https://leetcode.cn/problems/check-completeness-of-a-binary-tree/
namespace class036 {

    // 不提交这个结构体
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    // 提交以下的函数
    // 如果测试数据量变大了就修改这个值
    const int MAXN = 101;

    // 完全二叉树的判断
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        // 是否遇到过左右两个孩子不双全的节点
        bool leaf = false;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if ((node->left == nullptr && node->right != nullptr) || (leaf && (node->left != nullptr || node->right != nullptr))) {
                return false;
            }
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
            if (node->left == nullptr || node->right == nullptr) {
                leaf = true;
            }
        }
        return true;
    }

} // namespace class036

