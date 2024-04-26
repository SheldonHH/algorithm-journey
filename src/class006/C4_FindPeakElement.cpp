#include <vector>
using namespace std;

class Solution {
public:
    // 峰值元素是指其值严格大于左右相邻值的元素
    // 给你一个整数数组 nums，已知任何两个相邻的值都不相等
    // 找到峰值元素并返回其索引
    // 数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
    // 你可以假设 nums[-1] = nums[n] = 无穷小
    // 你必须实现时间复杂度为 O(log n) 的算法来解决此问题。
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0; // 如果数组只有一个元素，那它就是峰值
        }
        if (nums[0] > nums[1]) {
            return 0; // 检查第一个元素是否是峰值
        }
        if (nums[n - 1] > nums[n - 2]) {
            return n - 1; // 检查最后一个元素是否是峰值
        }

        int l = 1, r = n - 2;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m - 1] > nums[m]) {
                r = m - 1;
            } else if (nums[m] < nums[m + 1]) {
                l = m + 1;
            } else {
                return m; // 如果 nums[m] 大于左右两边，找到峰值
            }
        }
        
        return -1; // 如果循环中没有找到峰值，返回 -1（虽然根据题意总是存在峰值）
    }
};
