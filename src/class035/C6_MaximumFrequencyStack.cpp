#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 最大频率栈
class FreqStack {
    int topTimes; // 出现的最大次数
    unordered_map<int, vector<int>> cntValues; // 每层节点
    unordered_map<int, int> valueTimes; // 每一个数出现了几次

public:
    FreqStack() : topTimes(0) {}

    void push(int val) {
        // 更新 val 的出现次数
        valueTimes[val] = valueTimes[val] + 1;

        // 当前次数
        int curTopTimes = valueTimes[val];

        // 确保 cntValues 中存在该次数的列表
        if (!cntValues.count(curTopTimes)) {
            cntValues[curTopTimes] = vector<int>();
        }

        // 将 val 添加到相应次数的列表中
        cntValues[curTopTimes].push_back(val);

        // 更新最大次数
        topTimes = max(topTimes, curTopTimes);
    }

    int pop() {
        // 获取最大次数列表
        vector<int>& topTimeValues = cntValues[topTimes];

        // 从列表中移除最后一个元素并返回
        int ans = topTimeValues.back();
        topTimeValues.pop_back();

        // 如果该列表为空，则从 cntValues 中移除并更新最大次数
        if (topTimeValues.empty()) {
            cntValues.erase(topTimes--);
        }

        // 减少该值的出现次数
        int times = valueTimes[ans];
        if (times == 1) {
            valueTimes.erase(ans);
        } else {
            valueTimes[ans] = times - 1;
        }

        return ans;
    }
};
