#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// 使用先序与中序遍历序列构造二叉树
// 测试链接: https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// 不提交这个类
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// 提交如下的方法
TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
    if (pre.empty() || in.empty() || pre.size() != in.size()) {
        return nullptr;
    }
    unordered_map<int, int> map;
    for (int i = 0; i < in.size(); i++) {
        map[in[i]] = i;
    }
    return construct(pre, 0, pre.size() - 1, in, 0, in.size() - 1, map);
}

TreeNode* construct(const vector<int>& pre, int l1, int r1, const vector<int>& in, int l2, int r2, unordered_map<int, int>& map) {
    if (l1 > r1) {
        return nullptr;
    }
    TreeNode* head = new TreeNode(pre[l1]);
    if (l1 == r1) {
        return head;
    }
    int k = map[pre[l1]];
    head->left = construct(pre, l1 + 1, l1 + k - l2, in, l2, k - 1, map);
    head->right = construct(pre, l1 + k - l2 + 1, r1, in, k + 1, r2, map);
    return head;
}
