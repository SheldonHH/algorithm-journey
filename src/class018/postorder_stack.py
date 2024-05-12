class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        # print("pos-order:", end=" ")
        h = root
        if h is not None:
            stack = [h]
            c = None
            while stack:
                c = stack[-1]
                if c.left is not None and h is not c.left and h is not c.right:
                    stack.append(c.left)
                elif c.right is not None and h is not c.right:
                    stack.append(c.right)
                else:
                    cur = stack.pop().val
                    ans.append(cur)
                    h = c
        return ans