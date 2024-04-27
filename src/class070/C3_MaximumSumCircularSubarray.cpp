#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Code03_MaximumSumCircularSubarray {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int all = nums[0], maxSum = nums[0], minSum = nums[0];
        int maxPre = nums[0], minPre = nums[0];
        
        for (int i = 1; i < n; i++) {
            all += nums[i];
            maxPre = max(nums[i], nums[i] + maxPre);
            maxSum = max(maxSum, maxPre);
            minPre = min(nums[i], nums[i] + minPre);
            minSum = min(minSum, minPre);
        }

        // Handle the case where all elements are negative
        if (all == minSum) {
            return maxSum;
        }
        // Return the maximum of normal max subarray and circular subarray
        return max(maxSum, all - minSum);
    }
};

int main() {
    Code03_MaximumSumCircularSubarray solution;
    vector<int> nums = {5, -3, 5};
    cout << "Maximum Circular Subarray Sum: " << solution.maxSubarraySumCircular(nums) << endl;
    return 0;
}
