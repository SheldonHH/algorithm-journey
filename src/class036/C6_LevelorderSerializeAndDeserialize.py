class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:
    # 序列化一个二叉树
    def serialize(self, root):
        """Encodes a tree to a single string."""
        def serialize_helper(node):
            if node is None:
                return "#,"
            return f"{node.val}," + serialize_helper(node.left) + serialize_helper(node.right)
        
        return serialize_helper(root)
    
    # 反序列化一个序列化的二叉树字符串
    def deserialize(self, data):
        """Decodes your encoded data to tree."""
        def deserialize_helper(values):
            value = next(values)
            if value == "#":
                return None
            node = TreeNode(int(value))
            node.left = deserialize_helper(values)
            node.right = deserialize_helper(values)
            return node
        
        values = iter(data.split(','))
        return deserialize_helper(values)
