class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 如果测试数据量增大，修改此值
MAXN = 3001

# 使用每次处理一层的优化 BFS 来计算二叉树的最大宽度
def width_of_binary_tree(root):
    if not root:
        return 0
    
    ans = 1
    nq = [None] * MAXN  # 节点队列
    iq = [0] * MAXN     # 索引队列
    l, r = 0, 0
    
    nq[r] = root
    iq[r] = 1
    r += 1
    
    while l < r:
        size = r - l
        # 计算当前层的宽度
        ans = max(ans, iq[r - 1] - iq[l] + 1)
        for i in range(size):
            node = nq[l]
            idx = iq[l]
            l += 1
            if node.left:
                nq[r] = node.left
                iq[r] = idx * 2
                r += 1
            if node.right:
                nq[r] = node.right
                iq[r] = idx * 2 + 1
                r += 1
    
    return ans

# 注意: 测试时，需要构建相应的二叉树结构来进行测试
