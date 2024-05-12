using System;
using System.Collections.Generic;

// Definition for a binary tree node.
public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int x) { val = x; left = null; right = null; }
}

public class Solution {
    public IList<int> InorderTraversal(TreeNode root) {
        List<int> ans = new List<int>();

        // Define a lambda expression with Action, since it needs to call itself
        Action<TreeNode> inorderHelper = null;
        inorderHelper = (node) => {
            if (node == null) return;
            inorderHelper(node.left);
            ans.Add(node.val);
            inorderHelper(node.right);
        };

        inorderHelper(root);
        return ans;
    }
}

public class MainClass {
    public static void Main() {
        // Example usage
        TreeNode node3 = new TreeNode(3);
        TreeNode node2 = new TreeNode(2);
        node2.left = node3;
        TreeNode root = new TreeNode(1);
        root.right = node2;

        Solution sol = new Solution();
        IList<int> output = sol.InorderTraversal(root);
        foreach (int val in output) {
            Console.WriteLine(val);
        } // Output should be 1, 3, 2
    }
}
