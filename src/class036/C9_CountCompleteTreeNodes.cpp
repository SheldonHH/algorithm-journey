#include <iostream>

using namespace std;

// 定义完全二叉树的结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// 计算完全二叉树的节点个数
int countNodes(TreeNode* head) {
    if (head == nullptr) {
        return 0;
    }
    return f(head, 1, mostLeft(head, 1));
}

// cur : 当前节点
// level : 当前节点所在的层数
// h : 整棵树的高度，不是当前节点子树的高度
// 功能 : 计算当前子树中的节点数
int f(TreeNode* cur, int level, int h) {
    if (level == h) {
        return 1;
    }
    if (mostLeft(cur->right, level + 1) == h) {
        // 如果当前节点的右子树的最左边节点能到达最深的层次
        return (1 << (h - level)) + f(cur->right, level + 1, h);
    } else {
        // 如果当前节点的右子树的最左边节点没有达到最深的层次
        return (1 << (h - level - 1)) + f(cur->left, level + 1, h);
    }
}

// cur : 当前节点
// level : 当前节点所在的层数
// 功能 : 返回从当前节点开始一直向左能达到的层数
int mostLeft(TreeNode* cur, int level) {
    while (cur != nullptr) {
        level++;
        cur = cur->left;
    }
    return level - 1;
}

// 主函数用于演示
int main() {
    // 创建树的节点用于测试
    TreeNode* root = new TreeNode{1};
    root->left = new TreeNode{2};
    root->right = new TreeNode{3};
    root->left->left = new TreeNode{4};
    root->left->right = new TreeNode{5};
    root->right->left = new TreeNode{6};

    // 计算节点个数
    cout << "The number of nodes in the complete binary tree is: " << countNodes(root) << endl;

    return 0;
}
