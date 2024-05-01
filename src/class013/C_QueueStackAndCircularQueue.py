from collections import deque

# 使用 Python 内置的双端队列（deque）来实现队列
class Queue1:
    def __init__(self):
        self.queue = deque()

    def is_empty(self):
        return not self.queue

    def offer(self, num):
        self.queue.append(num)

    def poll(self):
        return self.queue.popleft()

    def peek(self):
        return self.queue[0]

    def size(self):
        return len(self.queue)

# 使用静态数组来实现队列
class Queue2:
    def __init__(self, n):
        self.queue = [0] * n
        self.l = 0
        self.r = 0
        self.capacity = n

    def is_empty(self):
        return self.l == self.r

    def offer(self, num):
        self.queue[self.r] = num
        self.r = (self.r + 1) % self.capacity

    def poll(self):
        val = self.queue[self.l]
        self.l = (self.l + 1) % self.capacity
        return val

    def head(self):
        return self.queue[self.l]

    def tail(self):
        return self.queue[(self.r - 1 + self.capacity) % self.capacity]

    def size(self):
        return (self.r - self.l + self.capacity) % self.capacity

# 使用 Python 的内置栈（实际上是使用 list 实现）
class Stack1:
    def __init__(self):
        self.stack = []

    def is_empty(self):
        return not self.stack

    def push(self, num):
        self.stack.append(num)

    def pop(self):
        return self.stack.pop()

    def peek(self):
        return self.stack[-1]

    def size(self):
        return len(self.stack)

# 使用静态数组来实现栈
class Stack2:
    def __init__(self, n):
        self.stack = [0] * n
        self.top = 0

    def is_empty(self):
        return self.top == 0

    def push(self, num):
        self.stack[self.top] = num
        self.top += 1

    def pop(self):
        self.top -= 1
        return self.stack[self.top]

    def peek(self):
        return self.stack[self.top - 1]

    def size(self):
        return self.top

# 实现循环队列
class MyCircularQueue:
    def __init__(self, k):
        self.queue = [0] * k
        self.l = 0
        self.r = 0
        self.size = 0
        self.limit = k

    def en_queue(self, value):
        if self.is_full():
            return False
        else:
            self.queue[self.r] = value
            self.r = (self.r + 1) % self.limit
            self.size += 1
            return True

    def de_queue(self):
        if self.is_empty():
            return False
        else:
            self.l = (self.l + 1) % self.limit
            self.size -= 1
            return True

    def front(self):
        if self.is_empty():
            return -1
        else:
            return self.queue[self.l]

    def rear(self):
        if self.is_empty():
            return -1
        else:
            last = 0 if self.r == 0 else self.r - 1
            return self.queue[last]

    def is_empty(self):
        return self.size == 0

    def is_full(self):
        return self.size == self.limit
