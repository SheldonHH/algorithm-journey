# 修剪搜索二叉树
# 测试链接 : https://leetcode.cn/problems/trim-a-binary-search-tree/

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def trimBST(cur, low, high):
    if cur is None:
        return None
    if cur.val < low:
        return trimBST(cur.right, low, high)
    if cur.val > high:
        return trimBST(cur.left, low, high)
    # cur在范围中
    cur.left = trimBST(cur.left, low, high)
    cur.right = trimBST(cur.right, low, high)
    return cur
