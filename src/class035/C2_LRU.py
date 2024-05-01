class LRUCache:
    class DoubleNode:
        def __init__(self, key, val):
            self.key = key
            self.val = val
            self.last = None
            self.next = None

    class DoubleList:
        def __init__(self):
            self.head = None
            self.tail = None

        def add_node(self, new_node):
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

    def __init__(self, capacity: int):
        self.key_node_map = {}
        self.node_list = self.DoubleList()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key in self.key_node_map:
            node = self.key_node_map[key]
            self.node_list.move_node_to_tail(node)
            return node.val
        return -1

    def put(self, key: int, value: int):
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
