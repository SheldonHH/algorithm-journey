#include <iostream>
#include <cmath> // For std::abs and std::max

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    static bool balance;

    static bool isBalanced(TreeNode* root) {
        // balance是全局变量，所有调用过程共享
        // 所以每次判断开始时，设置为true
        balance = true;
        height(root);
        return balance;
    }

    static int height(TreeNode* cur) {
        if (!balance || cur == nullptr) {
            return 0;
        }
        int lh = height(cur->left);
        int rh = height(cur->right);
        if (abs(lh - rh) > 1) {
            balance = false;
        }
        return max(lh, rh) + 1;
    }
};

bool Solution::balance = true;

int main() {
    // 测试代码
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    cout << "Is balanced? " << (Solution::isBalanced(root) ? "Yes" : "No") << endl;

    return 0;
}
