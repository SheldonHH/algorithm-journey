#include <vector>
#include <iostream>
using namespace std;

// 在数组中找到两种出现了奇数次的数，其他的数都出现了偶数次
vector<int> singleNumber(const vector<int>& nums) {
    int eor1 = 0;
    for (int num : nums) {
        // nums中有两种数a和b出现了奇数次，其他的数都出现了偶数次
        eor1 ^= num;
    }


    
    // eor1 = a ^ b
    // 使用 Brian Kernighan 算法提取出二进制里最右侧的1
    int rightOne = eor1 & (-eor1);
    int eor2 = 0; //只选择第三位上不是1的数
    for (int num : nums) {
        // 根据rightOne的位来分组
        if ((num & rightOne) == 0) {
            eor2 ^= num;
        }
    }
    // 返回结果，其中一个是eor2，另一个是eor1和eor2的异或结果
    return {eor2, eor1 ^ eor2};
}

} // namespace std

int main() {
    vector<int> nums = {2, 3, 3, 4, 4, 2, 5, 6}; // 示例数组
    vector<int> result = std::singleNumber(nums);
    cout << "两个只出现奇数次的数是：" << result[0] << " 和 " << result[1] << endl;
    return 0;
}
