#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// 先序遍历（非递归实现）
void preOrder(TreeNode *head) {
    if (head != nullptr) {
        stack<TreeNode*> s;
        s.push(head);
        while (!s.empty()) {
            head = s.top(); s.pop();
            cout << head->val << " ";
            if (head->right != nullptr) {
                s.push(head->right);
            }
            if (head->left != nullptr) {
                s.push(head->left);
            }
        }
        cout << endl;
    }
}

// 中序遍历（非递归实现）
void inOrder(TreeNode *head) {
    stack<TreeNode*> s;
    while (!s.empty() || head != nullptr) {
        if (head != nullptr) {
            s.push(head);
            head = head->left;
        } else {
            head = s.top(); s.pop();
            cout << head->val << " ";
            head = head->right;
        }
    }
    cout << endl;
}

// 后序遍历，使用两个栈（非递归实现）
void posOrderTwoStacks(TreeNode *head) {
    if (head != nullptr) {
        stack<TreeNode*> s1, s2;
        s1.push(head);
        while (!s1.empty()) {
            head = s1.top(); s1.pop();
            s2.push(head);
            if (head->left != nullptr) {
                s1.push(head->left);
            }
            if (head->right != nullptr) {
                s1.push(head->right);
            }
        }
        while (!s2.empty()) {
            head = s2.top(); s2.pop();
            cout << head->val << " ";
        }
        cout << endl;
    }
}

// 后序遍历，使用一个栈（非递归实现）
void posOrderOneStack(TreeNode *h) {
    if (h != nullptr) {
        stack<TreeNode*> s;
        TreeNode *lastPrint = nullptr;
        s.push(h);
        while (!s.empty()) {
            TreeNode *cur = s.top();
            if (cur->left != nullptr && lastPrint != cur->left && lastPrint != cur->right) {
                s.push(cur->left);
            } else if (cur->right != nullptr && lastPrint != cur->right) {
                s.push(cur->right);
            } else { 
                cout << cur->val << " ";
                lastPrint = cur;
                s.pop();
            }
        }
        cout << endl;
    }
}

// 测试主函数
int main() {
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(7);

    preOrder(head);
    cout << "先序遍历非递归版" << endl;
    inOrder(head);
    cout << "中序遍历非递归版" << endl;
    posOrderTwoStacks(head);
    cout << "后序遍历非递归版 - 2个栈实现" << endl;
    posOrderOneStack(head);
    cout << "后序遍历非递归版 - 1个栈实现" << endl;

    return 0;
}
