import random

class RandomizedCollection:
    def __init__(self):
        # 创建一个字典来存储值到其索引集合的映射
        self.map = {}
        # 创建一个列表来存储元素
        self.arr = []

    def insert(self, val):
        # 将值添加到列表末尾
        self.arr.append(val)

        # 获取值在map中的索引集合
        if val not in self.map:
            self.map[val] = set()

        # 将新元素的索引添加到集合中
        self.map[val].add(len(self.arr) - 1)

        # 返回集合是否只有一个元素
        return len(self.map[val]) == 1

    def remove(self, val):
        if val not in self.map or not self.map[val]:
            return False

        # 获取要移除的值的索引集合
        valSet = self.map[val]
        valAnyIndex = valSet.pop()

        # 获取列表末尾的值
        endValue = self.arr[-1]

        if valAnyIndex != len(self.arr) - 1:
            # 用列表末尾的值替换要移除的值
            self.arr[valAnyIndex] = endValue

            # 更新末尾值的索引集合
            self.map[endValue].add(valAnyIndex)
            self.map[endValue].remove(len(self.arr) - 1)

        # 从列表中移除末尾元素
        self.arr.pop()

        # 如果val的索引集合为空，则从map中移除
        if not valSet:
            del self.map[val]

        return True

    def getRandom(self):
        # 随机返回列表中的一个元素
        return self.arr[random.randint(0, len(self.arr) - 1)]
