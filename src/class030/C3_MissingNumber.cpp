#include <vector>

namespace std {

// 类030：找到缺失的数字
// 测试链接：https://leetcode.cn/problems/missing-number/
class Code03_MissingNumber {
public:
    static int missingNumber(vector<int>& nums) {
        int eorAll = 0, eorHas = 0;
        for (int i = 0; i < nums.size(); i++) {
            eorAll ^= i; // XOR 所有的索引
            eorHas ^= nums[i]; // XOR 数组中的所有数字
        }
        eorAll ^= nums.size(); // XOR 最后一个索引（数组长度）
        return eorAll ^ eorHas; // 返回缺失的数字
    }
};

} // namespace std
