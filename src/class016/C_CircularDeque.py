from collections import deque

class Queue1:
    # 使用 C++ 的内部实现，内部通常使用双向链表
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


class Queue2:
    # 使用静态数组来实现队列
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


class Stack1:
    # 使用 C++ 内部的 stack 实现
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


class Stack2:
    # 使用静态数组来实现栈
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


class MyCircularQueue:
    # 实现循环队列
    def __init__(self, k):
        self.queue = [0] * k
        self.l = 0
        self.r = 0
        self.size = 0
        self.limit = k

    def en_queue(self, value):
        if self.is_full():
            return False
        self.queue[self.r] = value
        self.r = (self.r + 1) % self.limit
        self.size += 1
        return True

    def de_queue(self):
        if self.is_empty():
            return False
        self.l = (self.l + 1) % self.limit
        self.size -= 1
        return True

    def front(self):
        return -1 if self.is_empty() else self.queue[self.l]

    def rear(self):
        if self.is_empty():
            return -1
        last = self.r - 1 if self.r > 0 else self.limit - 1
        return self.queue[last]

    def is_empty(self):
        return self.size == 0

    def is_full(self):
        return self.size == self.limit
