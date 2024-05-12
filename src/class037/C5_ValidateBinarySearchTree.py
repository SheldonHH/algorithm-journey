class TreeNode:
    """树节点定义"""
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# 全局变量定义
MAXN = 10001
stack = [None] * MAXN
r = 0
min_val = float('inf')
max_val = float('-inf')

def isValidBST1(head):
    """使用中序遍历的迭代方式检查二叉搜索树"""
    global r, stack
    if head is None:
        return True
    pre = None
    r = 0
    while r > 0 or head is not None:
        if head is not None:
            stack[r] = head
            r += 1
            head = head.left
        else:
            head = stack[r - 1]
            r -= 1
            if pre is not None and pre.val >= head.val:
                return False
            pre = head
            head = head.right
    return True

def isValidBST2(head):
    """使用递归方式检查二叉搜索树，并更新最小值和最大值"""
    global min_val, max_val
    if head is None:
        min_val = float('inf')
        max_val = float('-inf')
        return True
    lok = isValidBST2(head.left)
    lmin = min_val
    lmax = max_val
    rok = isValidBST2(head.right)
    rmin = min_val
    rmax = max_val
    min_val = min(min(lmin, rmin), head.val)
    max_val = max(max(lmax, rmax), head.val)
    return lok and rok and lmax < head.val and head.val < rmin

# 注意：在实际提交代码时需要将函数名从 isValidBST1 和 isValidBST2 修改为 isValidBST
