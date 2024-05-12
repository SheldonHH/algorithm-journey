#include <iostream>

// 使用 std 命名空间的所有成员
using namespace std;

// 递归序的解释
// 用递归实现二叉树的三序遍历
class BinaryTreeTraversalRecursion {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    };

    // 递归基本样子，用来理解递归序
    static void f(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        // 1
        f(head->left);
        // 2
        f(head->right);
        // 3
    }

    // 先序打印所有节点，递归版
    static void preOrder(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        cout << head->val << " ";
        preOrder(head->left);
        preOrder(head->right);
    }

    // 中序打印所有节点，递归版
    static void inOrder(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        inOrder(head->left);
        cout << head->val << " ";
        inOrder(head->right);
    }

    // 后序打印所有节点，递归版
    static void posOrder(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        posOrder(head->left);
        posOrder(head->right);
        cout << head->val << " ";
    }

    static void main() {
        TreeNode* head = new TreeNode(1);
        head->left = new TreeNode(2);
        head->right = new TreeNode(3);
        head->left->left = new TreeNode(4);
        head->left->right = new TreeNode(5);
        head->right->left = new TreeNode(6);
        head->right->right = new TreeNode(7);

        preOrder(head);
        cout << endl;
        cout << "先序遍历递归版" << endl;

        inOrder(head);
        cout << endl;
        cout << "中序遍历递归版" << endl;

        posOrder(head);
        cout << endl;
        cout << "后序遍历递归版" << endl;
    }
};

int main() {
    BinaryTreeTraversalRecursion::main();
    return 0;
}
