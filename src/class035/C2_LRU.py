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
            if new_node is None:  # 捣乱的滚
                return
            if self.head is None:
                self.head = new_node
                self.tail = new_node
            else:
                self.tail.next = new_node
                new_node.last = self.tail  # 指向老尾巴
                self.tail = new_node  # 你成为新尾巴

        def move_node_to_tail(self, node):
            """
            将一个节点移动到链表的尾部。
            :param node: 要移动的节点
            """
            if self.tail == node:  # 本来就是最晚最新被调用的
                return
            if self.head == node:
                self.head = node.next  # 头后移
                if self.head:
                    self.head.last = None  # 头last指针标空，悬空
            else:
                node.last.next = node.next  # 前节点的next指针指向我的后面
                if node.next:
                    node.next.last = node.last  # 我的下一个节点的last指针指向我的前面

            node.last = self.tail  # 我的last指向尾巴
            node.next = None  # 我的next设置为null
            self.tail.next = node  # 尾巴的next指向node
            self.tail = node  # 你成为新尾巴

        def remove_head(self):
            """
            移除并返回链表的头节点。
            :return: 被移除的节点
            """
            if self.head is None:  # 不用移除了
                return None
            ans = self.head
            if self.head == self.tail:  # 只有一个节点时
                self.head = None
                self.tail = None
            else:
                self.head = ans.next  # 下一个节点做头
                self.head.last = None  # ans  head(左指向右断链)
                ans.next = None  # ans  head(右指向左断链)
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
            self.node_list.move_node_to_tail(node)  # 返回给用户之前，在时间序列上移动到尾巴上
            return node.val
        return -1  # 没记录

    def put(self, key, value):
        """
        向缓存中添加或更新键值对。
        :param key: 要添加或更新的键
        :param value: 键对应的值
        """
        if key in self.key_node_map:  # 更新即可，无需真的插入
            node = self.key_node_map[key]
            node.val = value
            self.node_list.move_node_to_tail(node)  # 双向链表维持时序，就很爽，扔到尾部
        else:
            if len(self.key_node_map) == self.capacity:  # 新增操作要讨论空间满还是没满
                removed_node = self.node_list.remove_head()  # 双向链表移出之后会返回，他的key在哈希表里面也删掉
                if removed_node:
                    del self.key_node_map[removed_node.key]  # 删掉之后头节点向下移动
            new_node = self.DoubleNode(key, value)  # 空间没问题
            self.key_node_map[key] = new_node
            self.node_list.add_node(new_node)

# LRU 缓存对象会这样被实例化和调用：
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key, value)
