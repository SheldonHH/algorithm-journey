class MinStack1:
    def __init__(self):
        # 构造函数
        self.data = []
        self.min = []

    def push(self, val):
        # 入栈
        self.data.append(val)
        if not self.min or val <= self.min[-1]:
            self.min.append(val)
        else:
            self.min.append(self.min[-1])

    def pop(self):
        # 出栈
        self.data.pop()
        self.min.pop()

    def top(self):
        # 获取栈顶元素
        return self.data[-1]

    def get_min(self):
        # 获取栈中的最小元素
        return self.min[-1]


class MinStack2:
    def __init__(self):
        # 构造函数
        self.data = []
        self.min = []

    def push(self, val):
        # 入栈
        self.data.append(val)
        if not self.min or val <= self.min[-1]:
            self.min.append(val)
        else:
            self.min.append(self.min[-1])

    def pop(self):
        # 出栈
        self.data.pop()
        self.min.pop()

    def top(self):
        # 获取栈顶元素
        return self.data[-1]

    def get_min(self):
        # 获取栈中的最小元素
        return self.min[-1]
