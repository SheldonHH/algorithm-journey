#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Code05_HouseRobberIV {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size(), l = *min_element(nums.begin(), nums.end()), r = *max_element(nums.begin(), nums.end());
        int m, ans = 0;
        while (l <= r) {
            m = (l + r) / 2;
            if (mostRob1(nums, n, m) >= k) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }

    // 当盗贼能力为ability时，返回盗贼最多能窃取的房屋数量
    int mostRob1(vector<int>& nums, int n, int ability) {
        if (n == 1) {
            return nums[0] <= ability ? 1 : 0;
        }
        if (n == 2) {
            return (nums[0] <= ability || nums[1] <= ability) ? 1 : 0;
        }
        vector<int> dp(n, 0);
        dp[0] = nums[0] <= ability ? 1 : 0;
        dp[1] = (nums[0] <= ability || nums[1] <= ability) ? 1 : 0;
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], (nums[i] <= ability ? 1 : 0) + dp[i - 2]);
        }
        return dp[n - 1];
    }

    // 空间压缩优化版本
    int mostRob2(vector<int>& nums, int n, int ability) {
        if (n == 1) {
            return nums[0] <= ability ? 1 : 0;
        }
        if (n == 2) {
            return (nums[0] <= ability || nums[1] <= ability) ? 1 : 0;
        }
        int prepre = nums[0] <= ability ? 1 : 0;
        int pre = (nums[0] <= ability || nums[1] <= ability) ? 1 : 0;
        int cur = 0;
        for (int i = 2; i < n; i++) {
            cur = max(pre, (nums[i] <= ability ? 1 : 0) + prepre);
            prepre = pre;
            pre = cur;
        }
        return pre;
    }

    // 贪心算法优化版本
    int mostRob3(vector<int>& nums, int n, int ability) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= ability) {
                ans++;
                i++;  // Skip next house
            }
        }
        return ans;
    }
};

int main() {
    Code05_HouseRobberIV solution;
    vector<int> nums = {2, 3, 2};
    int k = 2;
    cout << "Minimum capability required to rob at least " << k << " houses: " << solution.minCapability(nums, k) << endl;
    return 0;
}
