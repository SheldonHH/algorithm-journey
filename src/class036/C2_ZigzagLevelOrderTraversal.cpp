#include <vector>
#include <deque>

using namespace std;

// 二叉树的锯齿形层序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    // 用每次处理一层的优化bfs就非常容易实现
    // 如果测试数据量变大了就修改这个值
    static const int MAXN = 2001;
    TreeNode* queue[MAXN];
    int l, r;

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root != nullptr) {
            l = r = 0;
            queue[r++] = root;
            // false 代表从左往右
            // true 代表从右往左
            bool reverse = false; 
            while (l < r) {
                int size = r - l;
                vector<int> list;
                // reverse == false, 左 -> 右， l....r-1, 收集size个
                // reverse == true, 右 -> 左， r-1....l, 收集size个
                // 左 -> 右, i = i + 1
                // 右 -> 左, i = i - 1
                int start = reverse ? r - 1 : l;  
                int step = reverse ? -1 : 1;              
                // 从 start 开始，根据 step 的正负值递增或递减 i  
                for (int i = start, k = 0; k < size; i += step, k++) { 
                    TreeNode* cur = queue[i];
                    list.push_back(cur->val);
                }
                for (int i = 0; i < size; i++) {
                    TreeNode* cur = queue[l++];
                    if (cur->left != nullptr) {
                        queue[r++] = cur->left;
                    }
                    if (cur->right != nullptr) {
                        queue[r++] = cur->right;
                    }
                }
                ans.push_back(list);
                reverse = !reverse;
            }
        }
        return ans;
    }
};
