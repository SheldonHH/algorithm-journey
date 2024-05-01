import heapq

class MedianFinder:
    def __init__(self):
        # 最大堆
        self.max_heap = []
        # 最小堆
        self.min_heap = []

    def balance(self):
        """保持两个堆的大小平衡"""
        if abs(len(self.max_heap) - len(self.min_heap)) == 2:
            if len(self.max_heap) > len(self.min_heap):
                # 从最大堆弹出顶元素并加入最小堆
                heapq.heappush(self.min_heap, -heapq.heappop(self.max_heap))
            else:
                # 从最小堆弹出顶元素并加入最大堆
                heapq.heappush(self.max_heap, -heapq.heappop(self.min_heap))

    def addNum(self, num):
        """添加一个数字到结构中"""
        if not self.max_heap or -self.max_heap[0] >= num:
            # 先添加到最大堆
            heapq.heappush(self.max_heap, -num)
        else:
            # 添加到最小堆
            heapq.heappush(self.min_heap, num)

        self.balance()

    def findMedian(self):
        """返回当前数据流的中位数"""
        if len(self.max_heap) == len(self.min_heap):
            # 两堆大小相等，返回顶元素的平均值
            return (-self.max_heap[0] + self.min_heap[0]) / 2.0
        else:
            # 返回较大堆的顶元素
            return -self.max_heap[0] if len(self.max_heap) > len(self.min_heap) else self.min_heap[0]
