class Code06_SortStackWithRecursive:
    @staticmethod
    def sort(stack):
        """主函数，对栈进行排序"""
        depth = Code06_SortStackWithRecursive.get_depth(stack)
        while depth > 0:
            max_value = Code06_SortStackWithRecursive.get_max(stack, depth)
            count = Code06_SortStackWithRecursive.get_count(stack, depth, max_value)
            Code06_SortStackWithRecursive.sink_max(stack, depth, max_value, count)
            depth -= count

    @staticmethod
    def get_depth(stack):
        """计算栈的深度，不改变栈的内容"""
        if not stack:
            return 0
        val = stack.pop()
        depth = 1 + Code06_SortStackWithRecursive.get_depth(stack)
        stack.append(val)
        return depth

    @staticmethod
    def get_max(stack, depth):
        """寻找栈中深度为depth的最大值"""
        if depth == 0:
            return float('-inf')
        val = stack.pop()
        rest_max = Code06_SortStackWithRecursive.get_max(stack, depth - 1)
        max_value = max(val, rest_max)
        stack.append(val)
        return max_value

    @staticmethod
    def get_count(stack, depth, max_value):
        """计算最大值max在栈中出现的次数"""
        if depth == 0:
            return 0
        val = stack.pop()
        rest_count = Code06_SortStackWithRecursive.get_count(stack, depth - 1, max_value)
        count = rest_count + (1 if val == max_value else 0)
        stack.append(val)
        return count

    @staticmethod
    def sink_max(stack, depth, max_value, k):
        """将最大值沉到栈底"""
        if depth == 0:
            for _ in range(k):
                stack.append(max_value)
        else:
            val = stack.pop()
            Code06_SortStackWithRecursive.sink_max(stack, depth - 1, max_value, k)
            if val != max_value:
                stack.append(val)

# 测试程序
def main():
    test = [1, 5, 4, 5, 3, 2, 3, 1, 4, 2]
    Code06_SortStackWithRecursive.sort(test)
    while test:
        print(test.pop())

    # 随机测试
    import random
    print("测试开始")
    for _ in range(20000):
        stack = [random.randint(0, 19) for _ in range(20)]
        Code06_SortStackWithRecursive.sort(stack)
        sorted_correctly = all(stack[i] <= stack[i + 1] for i in range(len(stack) - 1))
        if not sorted_correctly:
            print("出错了!")
            break
    else:
        print("测试结束")

if __name__ == '__main__':
    main()
