#include <queue>
#include <functional>
#include <cmath>
#include <iostream>
using namespace std;

// 快速获得数据流的中位数的结构
class MedianFinder {
    priority_queue<int> maxHeap; // 最大堆
    priority_queue<int, vector<int>, greater<int>> minHeap; // 最小堆

    void balance() {
        // 保持两个堆的大小平衡
        if (abs(static_cast<int>(maxHeap.size()) - static_cast<int>(minHeap.size())) == 2) {
            if (maxHeap.size() > minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }

public:
    MedianFinder() {}

    void addNum(int num) {
        if (maxHeap.empty() || maxHeap.top() >= num) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        balance();
    }

    double findMedian() const {
        // 如果两个堆的大小相等，则返回中位数
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        // 否则返回较大的堆顶元素
        return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
    }
};
