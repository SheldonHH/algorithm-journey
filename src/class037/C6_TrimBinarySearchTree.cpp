#include <iostream>

using namespace std;

// 修剪搜索二叉树
// 测试链接 : https://leetcode.cn/problems/trim-a-binary-search-tree/

// 不提交这个类
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 提交以下的方法
// [low, high]
TreeNode* trimBST(TreeNode* cur, int low, int high) {
    if (cur == nullptr) {
        return nullptr;
    }
    if (cur->val < low) {
        return trimBST(cur->right, low, high);
    }
    if (cur->val > high) {
        return trimBST(cur->left, low, high);
    }
    // cur在范围中
    cur->left = trimBST(cur->left, low, high);
    cur->right = trimBST(cur->right, low, high);
    return cur;
}
