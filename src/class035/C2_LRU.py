class LRUCache(object):
    class DoubleNode:
        def __init__(self, key, val):
            """
            初始化双向链表节点。
            :param key: 键
            :param val: 值
            """
            self.key = key
            self.val = val
            self.last = None
            self.next = None

    class DoubleList:
        def __init__(self):
            """
            初始化双向链表结构，包括头节点和尾节点。
            """
            self.head = None
            self.tail = None

        def add_node(self, new_node):
            """
            在链表的尾部添加一个新节点。
            :param new_node: 要添加的新节点
            """
            if new_node is None:
                return
            if self.head is None:
                self.head = new_node
                self.tail = new_node
            else:
                self.tail.next = new_node
                new_node.last = self.tail
                self.tail = new_node

        def move_node_to_tail(self, node):
            """
            将一个节点移动到链表的尾部。
            :param node: 要移动的节点
            """
            if self.tail == node:
                return
            if self.head == node:
                self.head = node.next
                if self.head:
                    self.head.last = None
            else:
                node.last.next = node.next
                if node.next:
                    node.next.last = node.last

            node.last = self.tail
            node.next = None
            self.tail.next = node
            self.tail = node

        def remove_head(self):
            """
            移除并返回链表的头节点。
            :return: 被移除的节点
            """
            if self.head is None:
                return None
            ans = self.head
            if self.head == self.tail:
                self.head = None
                self.tail = None
            else:
                self.head = ans.next
                self.head.last = None
                ans.next = None
            return ans

    def __init__(self, capacity):
        """
        初始化 LRU 缓存。
        :param capacity: 缓存容量
        """
        self.key_node_map = {}
        self.node_list = self.DoubleList()
        self.capacity = capacity

    def get(self, key):
        """
        获取缓存中指定键的值，如果键不存在则返回-1。
        :param key: 要获取值的键
        :return: 键对应的值，如果键不存在则返回-1
        """
        if key in self.key_node_map:
            node = self.key_node_map[key]
            self.node_list.move_node_to_tail(node)
            return node.val
        return -1

    def put(self, key, value):
        """
        向缓存中添加或更新键值对。
        :param key: 要添加或更新的键
        :param value: 键对应的值
        """
        if key in self.key_node_map:
            node = self.key_node_map[key]
            node.val = value
            self.node_list.move_node_to_tail(node)
        else:
            if len(self.key_node_map) == self.capacity:
                removed_node = self.node_list.remove_head()
                if removed_node:
                    del self.key_node_map[removed_node.key]
            new_node = self.DoubleNode(key, value)
            self.key_node_map[key] = new_node
            self.node_list.add_node(new_node)

# LRU 缓存对象会这样被实例化和调用：
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key, value)
