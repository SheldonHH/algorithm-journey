#include <algorithm>
#include <climits>

using namespace std;

// 求二叉树的最大、最小深度
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    // 测试链接 : https://leetcode.cn/problems/maximum-depth-of-binary-tree/
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            // 当前的树是空树
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    // 测试链接 : https://leetcode.cn/problems/minimum-depth-of-binary-tree/
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            // 当前的树是空树
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            // 当前root是叶节点
            return 1;
        }
        int leftDepth = INT_MAX;
        int rightDepth = INT_MAX;
        if (root->left != null) {
            leftDepth = minDepth(root->left);
        }
        if (root->right != null) {
            rightDepth = minDepth(root->right);
        }
        return min(leftDepth, rightDepth) + 1;
    }
};
