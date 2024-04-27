#include <climits> // For INT_MAX and INT_MIN
#include <vector>
using namespace std;

// 二叉树节点定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
    // 定义堆栈存储树的节点，最大容量为10001
    static const int MAXN = 10001;
    vector<TreeNode*> stack;
    int r;

    // 检验二叉搜索树方法1
    bool isValidBST1(TreeNode* head) {
        if (head == nullptr) {
            return true;
        }
        TreeNode* pre = nullptr;
        r = 0;
        stack.resize(MAXN);
        while (r > 0 || head != nullptr) {
            if (head != nullptr) {
                stack[r++] = head;
                head = head->left;
            } else {
                head = stack[--r];
                if (pre != nullptr && pre->val >= head->val) {
                    return false;
                }
                pre = head;
                head = head->right;
            }
        }
        return true;
    }

    // 用于存储子树的最小值和最大值
    long minn, maxx;

    // 检验二叉搜索树方法2
    bool isValidBST2(TreeNode* head) {
        if (head == nullptr) {
            minn = LONG_MAX;
            maxx = LONG_MIN;
            return true;
        }
        bool lok = isValidBST2(head->left);
        long lmin = minn;
        long lmax = maxx;
        bool rok = isValidBST2(head->right);
        long rmin = minn;
        long rmax = maxx;
        minn = min({lmin, rmin, head->val});
        maxx = max({lmax, rmax, head->val});
        return lok && rok && lmax < head->val && head->val < rmin;
    }
};
