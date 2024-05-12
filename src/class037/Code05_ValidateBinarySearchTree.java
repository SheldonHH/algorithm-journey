package class037;

// 验证搜索二叉树
// 测试链接 : https://leetcode.cn/problems/validate-binary-search-tree/
public class Code05_ValidateBinarySearchTree {

	// 不提交这个类
	public static class TreeNode {
		public int val;
		public TreeNode left;
		public TreeNode right;
	}

	// 提交以下的方法
	public static int MAXN = 10001;

	public static TreeNode[] stack = new TreeNode[MAXN];

	public static int r;

	// 提交时改名为isValidBST
	public static boolean isValidBST1(TreeNode head) {
		if (head == null) {
			return true;
		}
		TreeNode pre = null;
		r = 0;
		while (r > 0 || head != null) {
			if (head != null) {
				stack[r++] = head;
				head = head.left;
			} else {
				head = stack[--r];
				if (pre != null && pre.val >= head.val) {
					return false;
				}
				pre = head;
				head = head.right;
			}
		}
		return true;
	}
};

const int MAXN = 10001;
TreeNode* stack[MAXN];
int r;

long minVal, maxVal;

class Solution {
public:
	// Function to validate if a tree is a BST
	bool isValidBST(TreeNode* root) {
		if (root == nullptr) {
			minVal = LONG_MAX;
			maxVal = LONG_MIN;
			return true;
		}
		bool leftOk = isValidBST(root->left);
		long leftMin = minVal;
		long leftMax = maxVal;

		bool rightOk = isValidBST(root->right);
		long rightMin = minVal;
		long rightMax = maxVal;

		minVal = min({leftMin, rightMin, static_cast<long>(root->val)});
		maxVal = max({leftMax, rightMax, static_cast<long>(root->val)});

		return leftOk && rightOk && leftMax < root->val && root->val < rightMin;
	}
};