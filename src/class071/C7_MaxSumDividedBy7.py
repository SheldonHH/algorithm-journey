#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Dynamic programming solution with O(n^2) time complexity
    int lengthOfLIS1(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    // Efficient solution using binary search with O(n * log(n)) time complexity
    int lengthOfLIS2(vector<int>& nums) {
        vector<int> ends;
        for (int num : nums) {
            auto it = lower_bound(ends.begin(), ends.end(), num);
            if (it == ends.end()) {
                ends.push_back(num);
            } else {
                *it = num;
            }
        }
        return ends.size();
    }

    // Binary search to find the first element >= num in a strictly increasing sequence
    int bs1(vector<int>& ends, int num) {
        int l = 0, r = ends.size() - 1, m, ans = -1;
        while (l <= r) {
            m = (l + r) / 2;
            if (ends[m] >= num) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }

    // Binary search to find the first element > num in a non-decreasing sequence
    int bs2(vector<int>& ends, int num) {
        int l = 0, r = ends.size() - 1, m, ans = -1;
        while (l <= r) {
            m = (l + r) / 2;
            if (ends[m] > num) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of LIS (O(n^2) version): " << sol.lengthOfLIS1(nums) << endl;
    cout << "Length of LIS (O(n log n) version): " << sol.lengthOfLIS2(nums) << endl;
    return 0;
}
