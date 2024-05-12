#include <vector>
#include <iostream>
#include <climits>
using namespace std;

class Code01_MaximumSubarray {
public:
    // 动态规划
    int maxSubArray1(const vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    // 空间压缩
    int maxSubArray2(const vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        for (int i = 1, pre = nums[0]; i < n; i++) {
            pre = max(nums[i], pre + nums[i]);
            ans = max(ans, pre);
        }
        return ans;
    }

    // 找到拥有最大累加和的子数组
    void extra(const vector<int>& nums, int& left, int& right, int& sum) {
        sum = INT_MIN;
        for (int l = 0, r = 0, pre = INT_MIN; r < nums.size(); r++) {
            if (pre >= 0) {
                pre += nums[r];
            } else {
                pre = nums[r];
                l = r;
            }
            if (pre > sum) {
                sum = pre;
                left = l;
                right = r;
            }
        }
    }
};

int main() {
    Code01_MaximumSubarray solution;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Max Subarray Sum (DP): " << solution.maxSubArray1(nums) << endl;
    cout << "Max Subarray Sum (Optimized): " << solution.maxSubArray2(nums) << endl;

    int left, right, sum;
    solution.extra(nums, left, right, sum);
    cout << "Max Subarray (Extra): Sum = " << sum << ", Left = " << left << ", Right = " << right << endl;

    return 0;
}
