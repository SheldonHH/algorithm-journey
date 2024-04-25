#include <iostream>
#include <algorithm>
using namespace std;

// 包裹类 class037
namespace class037 {

// 二叉树打家劫舍问题
// 测试链接 : https://leetcode.cn/problems/house-robber-iii/
class Code07_HouseRobberIII {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    // 提交以下方法
    static int rob(TreeNode* root) {
        f(root);
        return max(yes, no);
    }

private:
    // 全局变量，完成了X子树的遍历，返回之后
    // yes变成，X子树在偷头节点的情况下，最大的收益
    static int yes;

    // 全局变量，完成了X子树的遍历，返回之后
    // no变成，X子树在不偷头节点的情况下，最大的收益
    static int no;

    static void f(TreeNode* root) {
        if (root == nullptr) {
            yes = 0;
            no = 0;
        } else {
            int y = root->val;
            int n = 0;
            f(root->left);
            y += no;
            n += max(yes, no);
            f(root->right);
            y += no;
            n += max(yes, no);
            yes = y;
            no = n;
        }
    }
};

// Initialize static members
int Code07_HouseRobberIII::yes = 0;
int Code07_HouseRobberIII::no = 0;

} // namespace class037
