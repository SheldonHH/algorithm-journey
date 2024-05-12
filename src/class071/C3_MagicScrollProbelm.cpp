#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>  // for rand()
#include <ctime>    // for time()

using namespace std;

class MagicScrollProblem {
public:
    // 暴力方法，用于测试
    int maxSum1(vector<int>& nums) {
        int p1 = 0;
        for (int num : nums) {
            p1 += num;
        }
        int n = nums.size();
        int p2 = mustOneScroll(nums, 0, n - 1);
        int p3 = INT_MIN;
        for (int i = 1; i < n; i++) {
            p3 = max(p3, mustOneScroll(nums, 0, i - 1) + mustOneScroll(nums, i, n - 1));
        }
        return max(p1, max(p2, p3));
    }

    // 暴力方法，为了测试
    // nums[l...r]范围上一定要用一次卷轴情况下的最大累加和
    int mustOneScroll(vector<int>& nums, int l, int r) {
        int ans = INT_MIN;
        for (int a = l; a <= r; a++) {
            for (int b = a; b <= r; b++) {
                int curAns = 0;
                for (int i = l; i < a; i++) {
                    curAns += nums[i];
                }
                for (int i = b + 1; i <= r; i++) {
                    curAns += nums[i];
                }
                ans = max(ans, curAns);
            }
        }
        return ans;
    }

    // 正式方法
    // 时间复杂度O(n)
    int maxSum2(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int p1 = accumulate(nums.begin(), nums.end(), 0);
        vector<int> prefix(n), suffix(n);
        int sum = nums[0];
        int maxPresum = max(0, nums[0]);
        prefix[0] = sum;
        for (int i = 1; i < n; i++) {
            sum += nums[i];
            maxPresum = max(maxPresum, sum);
            prefix[i] = max(prefix[i - 1], maxPresum);
        }
        sum = nums[n - 1];
        maxPresum = max(0, sum);
        suffix[n - 1] = sum;
        for (int i = n - 2; i >= 0; i--) {
            sum += nums[i];
            maxPresum = max(maxPresum, sum);
            suffix[i] = max(suffix[i + 1], maxPresum);
        }
        int p2 = prefix[n - 1];
        int p3 = INT_MIN;
        for (int i = 1; i < n; i++) {
            p3 = max(p3, prefix[i - 1] + suffix[i]);
        }
        return max(p1, max(p2, p3));
    }
};

// 为了测试
vector<int> randomArray(int n, int v) {
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = rand() % (v * 2 + 1) - v;
    }
    return ans;
}

int main() {
    srand(time(nullptr));  // Initialize random number generator
    int n = 50;
    int v = 100;
    int testTime = 10000;
    cout << "测试开始" << endl;
    MagicScrollProblem solver;
    for (int i = 0; i < testTime; i++) {
        int len = rand() % n;
        vector<int> nums = randomArray(len, v);
        int ans1 = solver.maxSum1(nums);
        int ans2 = solver.maxSum2(nums);
        if (ans1 != ans2) {
            cout << "出错了!" << endl;
        }
    }
    cout << "测试结束" << endl;
    return 0;
}
