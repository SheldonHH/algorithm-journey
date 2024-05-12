class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 使用普通 BFS 来进行层序遍历，不推荐此方法
def level_order1(root):
    ans = []
    if root:
        queue = []
        levels = {}
        queue.append(root)
        levels[root] = 0
        while queue:
            cur = queue.pop(0)
            level = levels[cur]
            if len(ans) == level:
                ans.append([])
            ans[level].append(cur.val)
            if cur.left:
                queue.append(cur.left)
                levels[cur.left] = level + 1
            if cur.right:
                queue.append(cur.right)
                levels[cur.right] = level + 1
    return ans

# 如果测试数据量增大，修改此值
MAXN = 2001
queue = [None] * MAXN
l = 0
r = 0

# 使用每次处理一层的优化 BFS 方法进行层序遍历，推荐此方法
def level_order2(root):
    global l, r
    ans = []
    if root:
        l, r = 0, 0
        queue[r] = root
        r += 1
        while l < r:  # 队列中还有节点
            size = r - l
            level_list = []
            for _ in range(size):
                cur = queue[l]
                l += 1
                level_list.append(cur.val)
                if cur.left:
                    queue[r] = cur.left
                    r += 1
                if cur.right:
                    queue[r] = cur.right
                    r += 1
            ans.append(level_list)
    return ans

# 注意: 测试时，需要构建相应的二叉树结构来进行测试
