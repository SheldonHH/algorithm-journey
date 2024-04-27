#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

namespace class071 {

// 暴力方法
// 为了测试
int maxSum1(vector<int>& nums, int k) {
    int n = nums.size();
    if (n <= k) {
        return 0;
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        vector<int> rest = nums; // Copy nums
        rest.erase(rest.begin() + i); // Delete the i-th element
        ans = max(ans, lenKmaxSum(rest, k));
    }
    return ans;
}

// 枚举每一个子数组找到最大累加和
int lenKmaxSum(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = INT_MIN;
    for (int i = 0; i <= n - k; i++) {
        int cur = 0;
        for (int j = i, cnt = 0; cnt < k; j++, cnt++) {
            cur += nums[j];
        }
        ans = max(ans, cur);
    }
    return ans;
}

// 正式方法
// 时间复杂度O(N)
int maxSum2(vector<int>& nums, int k) {
    int n = nums.size();
    if (n <= k) {
        return 0;
    }
    // 单调队列 : 维持窗口内最小值的更新结构，讲解054的内容
    vector<int> window(n);
    int l = 0, r = 0;
    // 窗口累加和
    long sum = 0;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        // 单调队列 : i位置进入单调队列
        while (l < r && nums[window[r - 1]] >= nums[i]) {
            r--;
        }
        window[r++] = i;
        sum += nums[i];
        if (i >= k) {
            ans = max(ans, static_cast<int>(sum - nums[window[l]]));
            if (window[l] == i - k) {
                // 单调队列 : 如果单调队列最左侧的位置过期了，从队列中弹出
                l++;
            }
            sum -= nums[i - k];
        }
    }
    return ans;
}

// 为了测试
// 生成长度为n，值在[-v, +v]之间的随机数组
vector<int> randomArray(int n, int v) {
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = rand() % (2 * v + 1) - v;
    }
    return ans;
}

// 为了测试
// 对数器
void test() {
    int n = 200;
    int v = 1000;
    int testTimes = 10000;
    cout << "测试开始" << endl;
    for (int i = 0; i < testTimes; i++) {
        int len = rand() % n + 1;
        vector<int> nums = randomArray(len, v);
        int k = rand() % n + 1;
        int ans1 = maxSum1(nums, k);
        int ans2 = maxSum2(nums, k);
        if (ans1 != ans2) {
            cout << "出错了!" << endl;
            break;
        }
    }
    cout << "测试结束" << endl;
}

} // namespace class071

int main() {
    class071::test();
    return 0;
}
