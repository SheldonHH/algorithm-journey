# 二叉树的锯齿形层序遍历
# 测试链接 : https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# 提交以下的方法
# 用每次处理一层的优化bfs就非常容易实现
# 如果测试数据量变大了就修改这个值
MAXN = 2001

queue = [None] * MAXN
l, r = 0, 0

def zigzagLevelOrder(root):
    ans = []
    if root is not None:
        global l, r
        l, r = 0, 0
        queue[r] = root
        r += 1
        # false 代表从左往右
        # true 代表从右往左
        reverse = False
        while l < r:
            size = r - l
            list_ = []
            # reverse == False, 左 -> 右, l....r-1, 收集size个
            # reverse == True, 右 -> 左, r-1....l, 收集size个
            # 左 -> 右, i = i + 1
            # 右 -> 左, i = i - 1
            for i in range(r-1, l-1, -1) if reverse else range(l, r):
                cur = queue[i]
                list_.append(cur.val)
            for i in range(size):
                cur = queue[l]
                l += 1
                if cur.left is not None:
                    queue[r] = cur.left
                    r += 1
                if cur.right is not None:
                    queue[r] = cur.right
                    r += 1
            ans.append(list_)
            reverse = not reverse
    return ans
