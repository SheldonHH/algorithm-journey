#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        for (int odd = 1, even = 0; odd < n && even < n;) {
            if ((nums[n - 1] & 1) == 1) { //奇数位
                swap(nums, odd, n - 1);
                odd += 2;
            } else { 
                swap(nums, even, n - 1); // 和偶数位置交换
                even += 2;
            }
        }
        return nums;
    }

    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
