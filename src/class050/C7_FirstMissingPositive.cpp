#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l = 0; // l的左边，都是做到i位置上放着i+1的区域
        int r = nums.size(); // [r....]是垃圾区
        // 试图将1~r范围内的数放到它应该在的位置上，即数值为i的数应该放在i-1的位置
        while (l < r) {
            if (nums[l] == l + 1) { // 如果l位置的数已经满足条件，则考察下一个，
            // l++，不用做
            } else if (nums[l] <= l || nums[l] > r || nums[nums[l] - 1] == nums[l]) { 
            // 如果l位置的数不在l~r范围内，扔到垃圾区  或者 无法放到正确的位置（因为那个位置上已经有一个相同的数了），
            // 当前数字与右侧边界的前一个数字交换
            // 并缩小右侧边界
            } else { 
                // 将l位置的数放到它应该去的位置
            }
        }
        // l左边的都是正好放好的，所以缺失的第一个正数是l+1
    }


};







#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l = 0; // l的左边，都是做到i位置上放着i+1的区域
        int r = nums.size(); // [r....]是垃圾区
        // 试图将1~r范围内的数放到它应该在的位置上，即数值为i的数应该放在i-1的位置
        while (l < r) {
            if (nums[l] == l + 1) { // 如果l位置的数已经满足条件，则考察下一个
                l++;
            } else if (nums[l] <= l || nums[l] > r || nums[nums[l] - 1] == nums[l]) { 
            // 如果l位置的数不在1~r范围内，或者无法放到正确的位置（因为那个位置上已经有一个相同的数了），则与r区的一个数交换
                swap(nums, l, --r);
            } else { // 将l位置的数放到它应该去的位置
                swap(nums, l, nums[l] - 1);
            }
        }
        return l + 1; // l左边的都是正好放好的，所以缺失的第一个正数是l+1
    }

    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 4, -1, 1}; // 示例数组
    cout << "The first missing positive is: " << solution.firstMissingPositive(nums) << endl;
    return 0;
}
