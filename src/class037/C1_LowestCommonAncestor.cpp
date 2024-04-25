#include <iostream>

using namespace std;

// 定义二叉树的节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 寻找两个节点的最近公共祖先
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // 如果根节点为空，或者根节点是p或q之一，直接返回根节点
    if (root == nullptr || root == p || root == q) {
        return root;
    }
    // 在左子树中查找
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    // 在右子树中查找
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    // 如果左右子树分别找到了p和q，那么当前根节点就是最近公共祖先
    if (left != nullptr && right != nullptr) {
        return root;
    }
    // 如果左右子树都没有找到，返回nullptr
    if (left == nullptr && right == nullptr) {
        return nullptr;
    }
    // 如果左子树或右子树中有一个找到了p或q，返回那个找到的节点
    return left != nullptr ? left : right;
}
