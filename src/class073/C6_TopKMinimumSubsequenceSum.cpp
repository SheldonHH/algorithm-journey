#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

// 非负数组前k个最小的子序列累加和
// 给定一个数组nums，含有n个数字，都是非负数
// 给定一个正数k，返回所有子序列中累加和最小的前k个累加和
// 子序列是包含空集的
// 1 <= n <= 10^5
// 1 <= nums[i] <= 10^6
// 1 <= k <= 10^5

// 暴力方法
vector<int> topKSum1(const vector<int>& nums, int k) {
    vector<int> allSubsequences;
    function<void(int, int)> f1 = [&](int index, int sum) {
        if (index == nums.size()) {
            allSubsequences.push_back(sum);
        } else {
            f1(index + 1, sum);
            f1(index + 1, sum + nums[index]);
        }
    };
    f1(0, 0);
    sort(allSubsequences.begin(), allSubsequences.end());
    vector<int> ans(k);
    for (int i = 0; i < k; i++) {
        ans[i] = allSubsequences[i];
    }
    return ans;
}

// 正式方法
// 用堆来做是最优解，时间复杂度O(n * log n) + O(k * log k)
vector<int> topKSum3(const vector<int>& nums, int k) {
    vector<int> sortedNums(nums);
    sort(sortedNums.begin(), sortedNums.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push({0, sortedNums[0]});
    vector<int> ans(k);
    ans[0] = 0; // Include the empty subsequence
    for (int i = 1; i < k; i++) {
        auto cur = heap.top();
        heap.pop();
        int right = cur.first;
        int sum = cur.second;
        ans[i] = sum;
        if (right + 1 < sortedNums.size()) {
            heap.push({right + 1, sum - sortedNums[right] + sortedNums[right + 1]});
            heap.push({right + 1, sum + sortedNums[right + 1]});
        }
    }
    return ans;
}

// 为了测试
vector<int> randomArray(int len, int value) {
    vector<int> ans(len);
    for (int i = 0; i < len; i++) {
        ans[i] = rand() % value;
    }
    return ans;
}

// 为了测试
bool equals(const vector<int>& ans1, const vector<int>& ans2) {
    if (ans1.size() != ans2.size()) {
        return false;
    }
    for (int i = 0; i < ans1.size(); i++) {
        if (ans1[i] != ans2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 15;
    int v = 40;
    int testTime = 5000;
    cout << "测试开始" << endl;
    for (int i = 0; i < testTime; i++) {
        int len = rand() % n + 1;
        vector<int> nums = randomArray(len, v);
        int k = rand() % ((1 << len) - 1) + 1;
        vector<int> ans1 = topKSum1(nums, k);
        vector<int> ans3 = topKSum3(nums, k);
        if (!equals(ans1, ans3)) {
            cout << "出错了！" << endl;
            break;
        }
    }
    cout << "测试结束" << endl;
    return 0;
}
