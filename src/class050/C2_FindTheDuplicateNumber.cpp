#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 检查数组是否有效，这里的条件检查有误，我将其删除
        // 因为数组为空的情况在C++中通过vector直接处理，且nums的大小至少为2是题目已知条件
        if (nums.empty() || nums.size() < 2){
            return -1;
        }
        int slow = nums[0];
        int fast = nums[nums[0]];
        // 使用do-while循环至少执行一次，确保slow与fast从不同的位置开始
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        // 当快慢指针相遇时，将快指针（或慢指针）移回数组起始位置
        fast = 0;
        // 然后以相同速度移动快慢指针直到它们再次相遇，相遇点即为重复数字
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
