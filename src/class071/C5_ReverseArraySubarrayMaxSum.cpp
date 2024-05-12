#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>  // for rand()
#include <ctime>    // for time()

using namespace std;

class Solution {
public:
    // Function to reverse a part of the array
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }

    // Function to find the maximum sum of a subarray
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0], pre = nums[0];
        for (int i = 1; i < n; i++) {
            pre = max(nums[i], pre + nums[i]);
            ans = max(ans, pre);
        }
        return ans;
    }

    // Brute-force method to verify
    int maxSumReverse1(vector<int>& nums) {
        int ans = INT_MIN;
        for (int l = 0; l < nums.size(); l++) {
            for (int r = l; r < nums.size(); r++) {
                reverse(nums, l, r);
                ans = max(ans, maxSum(nums));
                reverse(nums, l, r);  // Reverse back to original state
            }
        }
        return ans;
    }

    // Optimized method with O(n) time complexity
    int maxSumReverse2(vector<int>& nums) {
        int n = nums.size();
        vector<int> start(n);
        start[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            start[i] = max(nums[i], nums[i] + start[i + 1]);
        }
        int ans = start[0];
        int end = nums[0], maxEnd = nums[0];
        for (int i = 1; i < n; i++) {
            ans = max(ans, maxEnd + start[i]);
            end = max(nums[i], end + nums[i]);
            maxEnd = max(maxEnd, end);
        }
        ans = max(ans, maxEnd);
        return ans;
    }
};

// Function to generate a random array
vector<int> randomArray(int n, int v) {
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = rand() % (v * 2 + 1) - v;
    }
    return ans;
}

// Main function to test the methods
int main() {
    srand(time(nullptr));  // Initialize random number generator
    int n = 50;
    int v = 200;
    int testTime = 20000;
    cout << "测试开始" << endl;
    Solution sol;
    for (int i = 0; i < testTime; i++) {
        int len = rand() % n + 1;
        vector<int> arr = randomArray(len, v);
        int ans1 = sol.maxSumReverse1(arr);
        int ans2 = sol.maxSumReverse2(arr);
        if (ans1 != ans2) {
            cout << "出错了!" << endl;
        }
    }
    cout << "测试结束" << endl;
    return 0;
}
