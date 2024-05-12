# Definition for a binary tree node.  
class TreeNode:  
    def __init__(self, val=0, left=None, right=None):  
        self.val = val  
        self.left = left  
        self.right = right  
  
class Solution:  
    def inorderTraversal(self, root: TreeNode) -> List[int]:  
        ans = []  # Initialize ans within the method  
          
        def helper(root):  
            nonlocal ans  # Refer to the ans defined in the enclosing function scope  
            if root is None:  
                return  
            helper(root.left)  
            ans.append(root.val)  
            helper(root.right)  
  
        helper(root)  # Call the inner function  
        return ans  
  
# Example usage  
node3 = TreeNode(3)  
node2 = TreeNode(2, node3)  
root = TreeNode(1, None, node2)  
  
sol = Solution()  
output = sol.inorderTraversal(root)  
print(output)  # Output should be [1, 3, 2]  