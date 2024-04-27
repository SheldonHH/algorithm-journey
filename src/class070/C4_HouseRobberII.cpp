#include <vector>
#include <algorithm>
using namespace std;

class Code04_HouseRobberII {
public:
    static int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        // Calculate max sum without considering the first element or the last element
        return max(best(nums, 1, n - 1), nums[0] + best(nums, 2, n - 2));
    }

    // Helper function to calculate the maximum sum in a non-circular array from index l to r
    static int best(vector<int>& nums, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == r) {
            return nums[l];
        }
        if (l + 1 == r) {
            return max(nums[l], nums[r]);
        }
        int prepre = nums[l];
        int pre = max(nums[l], nums[l + 1]);
        for (int i = l + 2; i <= r; i++) {
            int cur = max(pre, nums[i] + max(0, prepre));
            prepre = pre;
            pre = cur;
        }
        return pre;
    }
};
