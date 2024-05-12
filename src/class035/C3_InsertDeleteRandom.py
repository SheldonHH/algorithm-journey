import random

# 插入、删除和获取随机元素O(1)时间的结构
class RandomizedSet:
    def __init__(self):
        # 存储值与其在列表中的索引的映射
        self.map = {}
        # 存储值的列表
        self.arr = []

    def insert(self, val):
        if val in self.map:
            return False
        # 将值添加到列表的末尾
        self.arr.append(val)
        # 更新映射
        self.map[val] = len(self.arr) - 1
        return True

    def remove(self, val):
        if val not in self.map:
            return False
        # 获取要删除的值的索引
        valIndex = self.map[val]
        # 获取列表最后一个值
        endValue = self.arr[-1]
        # 将最后一个值移动到被删除值的位置
        self.arr[valIndex] = endValue
        self.map[endValue] = valIndex
        # 从列表中删除最后一个元素
        self.arr.pop()
        # 从映射中删除该值
        del self.map[val]
        return True

    def getRandom(self):
        # 返回列表中随机的一个值
        return random.choice(self.arr)
