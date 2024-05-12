#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Helper function for brute force recursion
int f1(vector<int>& nums, int target, int i, int sum) {
    if (i == nums.size()) {
        return sum == target ? 1 : 0;
    }
    return f1(nums, target, i + 1, sum + nums[i]) + f1(nums, target, i + 1, sum - nums[i]);
}

// Brute force recursive solution
int findTargetSumWays1(vector<int>& nums, int target) {
    return f1(nums, target, 0, 0);
}

// Helper function for memoized recursion
int f2(vector<int>& nums, int target, int i, int j, unordered_map<int, unordered_map<int, int>>& dp) {
    if (i == nums.size()) {
        return j == target ? 1 : 0;
    }
    if (dp.count(i) && dp[i].count(j)) {
        return dp[i][j];
    }
    int ans = f2(nums, target, i + 1, j + nums[i], dp) + f2(nums, target, i + 1, j - nums[i], dp);
    dp[i][j] = ans;
    return ans;
}

// Memoized recursive solution
int findTargetSumWays2(vector<int>& nums, int target) {
    unordered_map<int, unordered_map<int, int>> dp;
    return f2(nums, target, 0, 0, dp);
}

// Dynamic programming with space optimization
int findTargetSumWays3(vector<int>& nums, int target) {
    int sum = 0;
    for (int num : nums) sum += num;
    if (target > sum || (sum - target) % 2 != 0) return 0;  // target is not reachable
    int s = (sum - target) / 2;
    vector<int> dp(s + 1, 0);
    dp[0] = 1;  // base case
    for (int num : nums) {
        for (int j = s; j >= num; j--) {
            dp[j] += dp[j - num];
        }
    }
    return dp[s];
}

// Main function to handle I/O
int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Number of ways: " << findTargetSumWays2(nums, target) << endl;  // Using memoized recursive for demonstration
    return 0;
}
