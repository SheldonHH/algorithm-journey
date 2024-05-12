class AllOne:
    class Bucket:
        def __init__(self, key, cnt):
            self.set = {key} if key else set()
            self.cnt = cnt
            self.last = None
            self.next = None

    def __init__(self):
        # 创建头尾两个哨兵桶
        self.head = self.Bucket("", 0)
        self.tail = self.Bucket("", float("inf"))
        self.head.next = self.tail
        self.tail.last = self.head
        # 创建哈希表存储键到桶的映射
        self.map = {}

    def insert(self, cur, pos):
        # 在当前桶cur后插入桶pos
        pos.next = cur.next
        pos.next.last = pos
        cur.next = pos
        pos.last = cur

    def remove(self, cur):
        # 移除当前桶cur
        cur.last.next = cur.next
        cur.next.last = cur.last

    def inc(self, key):
        if key not in self.map:
            # 如果key不存在于哈希表中
            if self.head.next.cnt == 1:
                self.map[key] = self.head.next
                self.head.next.set.add(key)
            else:
                new_bucket = self.Bucket(key, 1)
                self.map[key] = new_bucket
                self.insert(self.head, new_bucket)
        else:
            # 如果key已经存在于哈希表中
            bucket = self.map[key]
            if bucket.next.cnt == bucket.cnt + 1:
                self.map[key] = bucket.next
                bucket.next.set.add(key)
            else:
                new_bucket = self.Bucket(key, bucket.cnt + 1)
                self.map[key] = new_bucket
                self.insert(bucket, new_bucket)
            bucket.set.remove(key)
            if not bucket.set:
                self.remove(bucket)

    def dec(self, key):
        if key not in self.map:
            return

        bucket = self.map[key]
        if bucket.cnt == 1:
            del self.map[key]
        else:
            if bucket.last.cnt == bucket.cnt - 1:
                self.map[key] = bucket.last
                bucket.last.set.add(key)
            else:
                new_bucket = self.Bucket(key, bucket.cnt - 1)
                self.map[key] = new_bucket
                self.insert(bucket.last, new_bucket)
        bucket.set.remove(key)
        if not bucket.set:
            self.remove(bucket)

    def getMaxKey(self):
        # 返回计数最高桶中的任意一个键
        if self.tail.last == self.head:
            return ""
        return next(iter(self.tail.last.set))

    def getMinKey(self):
        # 返回计数最低桶中的任意一个键
        if self.head.next == self.tail:
            return ""
        return next(iter(self.head.next.set))
