
from collections import deque
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode):
        if not root:
            return []

        results = []
        queue = deque([root])
        reverse = False

        while queue:
            size = len(queue)
            level = []
            # 计算起始位置和步长
            start = len(queue) - 1 if reverse else 0
            step = -1 if reverse else 1

            # 从 start 开始，根据 step 的正负值递增或递减 i
            for i, k in zip(range(start, start + size * step, step), range(size)):
                node = queue[i]
                level.append(node.val)

            # 进行下一层节点的追加
            new_queue = deque()
            while queue:
                node = queue.popleft()
                if node.left:
                    new_queue.append(node.left)
                if node.right:
                    new_queue.append(node.right)
            
            queue = new_queue
            results.append(level)
            reverse = not reverse

        return results