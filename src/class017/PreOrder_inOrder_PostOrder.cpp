#include <iostream>
#include <vector>
#include <functional> // For function

using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        // function is needed to use a lambda that calls itself
        function<void(TreeNode*)> inorderHelper = [&](TreeNode* node) {
            if (node == nullptr) return;
            inorderHelper(node->left);
            ans.push_back(node->val);
            inorderHelper(node->right);
        };

        inorderHelper(root);
        return ans;
    }
};

int main() {
    // Example usage
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(2);
    node2->left = node3;
    TreeNode* root = new TreeNode(1);
    root->right = node2;

    Solution sol;
    vector<int> output = sol.inorderTraversal(root);
    for (int val : output) {
        cout << val << " ";
    } // Output should be 1 3 2

    return 0;
}
