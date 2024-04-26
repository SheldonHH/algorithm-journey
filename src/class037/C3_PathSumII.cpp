#include <iostream>
#include <vector>
using namespace std;

// 定义树的节点结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 收集累加和等于aim的所有路径
// 测试链接 : https://leetcode.cn/problems/path-sum-ii/
class Code03_PathSumII {
public:
    // 提交以下的方法
    vector<vector<int>> pathSum(TreeNode* root, int aim) {
        vector<vector<int>> ans;
        if (root != nullptr) {
            vector<int> path;
            f(root, aim, 0, path, ans);
        }
        return ans;
    }

private:
    void f(TreeNode* cur, int aim, int sum, vector<int>& path, vector<vector<int>>& ans) {
        if (cur->left == nullptr && cur->right == nullptr) {
            // 叶节点
            if (cur->val + sum == aim) {
                path.push_back(cur->val); // 加入自己
                copy(path, ans); // path生成好
                path.pop_back(); // 从path中移除最后一个
            }
        } else {
            // 不是叶节点
            path.push_back(cur->val);
            if (cur->left != nullptr) { // 左非空
                f(cur->left, aim, sum + cur->val, path, ans);
            }
            if (cur->right != nullptr) { // 右非空
                f(cur->right, aim, sum + cur->val, path, ans);
            }
            path.pop_back(); //删掉自己，恢复现场
        }
    }

    void copy(const vector<int>& path, vector<vector<int>>& ans) {
        ans.push_back(vector<int>(path.begin(), path.end()));
    }
};
