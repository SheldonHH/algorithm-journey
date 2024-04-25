#include <iostream>
using namespace std;

// 定义二叉搜索树的节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 寻找二叉搜索树中两个节点的最近公共祖先
// 测试链接：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
class Solution {
public:
    // 主函数，寻找最近公共祖先
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 从root开始向下寻找
        // 如果先遇到了p，说明p就是答案
        // 如果先遇到了q，说明q就是答案
        // 如果root的值在p和q的值之间，说明当前的root就是最近的公共祖先
        // 如果root的值在p和q的值的左侧，那么向右子树移动
        // 如果root的值在p和q的值的右侧，那么向左子树移动
        while (root->val != p->val && root->val != q->val) {
            if (min(p->val, q->val) < root->val && root->val < max(p->val, q->val)) {
                break; // 找到公共祖先
            }
            root = root->val < min(p->val, q->val) ? root->right : root->left;
        }
        return root;
    }
};
