class Main:
    map = {}  # 使用字典代替C++中的unordered_map
    setAllValue = 0  # setAll 操作的值
    setAllTime = -1  # setAll 操作的时间戳
    cnt = 0  # 每进入一个值就++

    @staticmethod
    def put(k, v):
        # 插入或更新键值对
        Main.map[k] = (v, Main.cnt)
        Main.cnt += 1

    @staticmethod
    def setAll(v):
        # 设置所有值为v，并记录时间戳
        Main.setAllValue = v
        Main.setAllTime = Main.cnt
        Main.cnt += 1

    @staticmethod
    def get(k):
        # 获取键k对应的值
        if k not in Main.map:
            return -1
        value, timestamp = Main.map[k]
        # 根据时间戳判断返回 setAllValue 还是自身的值
        if timestamp > Main.setAllTime:
            return value
        else:
            return Main.setAllValue

    @staticmethod
    def process():
        data = input().split()  # 读取输入数据并分割成列表
        idx = 0
        n = int(data[idx])  # 读取操作数量 n
        idx += 1
        for _ in range(n):  # 遍历每个操作
            op = int(data[idx])  # 读取操作码 op
            idx += 1
            if op == 1:
                a = int(data[idx])  # 读取参数 a
                idx += 1
                b = int(data[idx])  # 读取参数 b
                idx += 1
                Main.put(a, b)  # 调用 put 方法
            elif op == 2:
                a = int(data[idx])  # 读取参数 a
                idx += 1
                print(Main.get(a))  # 输出 get 方法的结果
            else:
                a = int(data[idx])  # 读取参数 a
                idx += 1
                Main.setAll(a)  # 调用 setAll 方法


                
if __name__ == "__main__":
    Main.process()