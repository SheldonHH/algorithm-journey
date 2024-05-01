class FreqStack:
    def __init__(self):
        # 出现的最大次数
        self.topTimes = 0
        # 每层节点
        self.cntValues = {}
        # 每个数出现了几次
        self.valueTimes = {}

    def push(self, val):
        # 更新val的出现次数
        self.valueTimes[val] = self.valueTimes.get(val, 0) + 1

        # 当前次数
        curTopTimes = self.valueTimes[val]

        # 确保cntValues中存在该次数的列表
        if curTopTimes not in self.cntValues:
            self.cntValues[curTopTimes] = []

        # 将val添加到相应次数的列表中
        self.cntValues[curTopTimes].append(val)

        # 更新最大次数
        self.topTimes = max(self.topTimes, curTopTimes)

    def pop(self):
        # 获取最大次数列表
        topTimeValues = self.cntValues[self.topTimes]

        # 从列表中移除最后一个元素并返回
        ans = topTimeValues.pop()

        # 如果该列表为空，则从cntValues中移除并更新最大次数
        if not topTimeValues:
            del self.cntValues[self.topTimes]
            self.topTimes -= 1

        # 减少该值的出现次数
        times = self.valueTimes[ans]
        if times == 1:
            del self.valueTimes[ans]
        else:
            self.valueTimes[ans] = times - 1

        return ans
