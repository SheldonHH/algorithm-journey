#include <iostream>
#include <vector>
#include <algorithm> // for std::min and std::max functions

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int ans = nums[0];
        int minProduct = nums[0];
        int maxProduct = nums[0];
        int curMin, curMax;

        for (int i = 1; i < nums.size(); i++) {
            curMin = min(nums[i], min(minProduct * nums[i], maxProduct * nums[i]));
            curMax = max(nums[i], max(minProduct * nums[i], maxProduct * nums[i]));
            minProduct = curMin;
            maxProduct = curMax;
            ans = max(ans, maxProduct);
        }

        return ans;
    }
};

int main() {
    // Example usage
    Solution sol;
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum product of subarray: " << sol.maxProduct(nums) << endl;
    return 0;
}
