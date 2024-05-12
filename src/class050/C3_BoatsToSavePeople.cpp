#include <vector>  
#include <algorithm> // 为了使用sort函数  
  
using namespace std;  
  
class Solution {  
public:  
    // 函数用于计算救所有人需要的最小船数  
    int numRescueBoats(vector<int>& people, int limit) {  
        // 对人的体重进行排序  
        sort(people.begin(), people.end());  
          
        int ans = 0; // 用于存储结果  
        int l = 0; // 左指针，从数组开始处  
        int r = people.size() - 1; // 右指针，从数组末尾处  
        int sum = 0; // 存储当前两个人的体重和  
          
        // 当左指针不超过右指针时循环  
        while (l <= r) {  
            // 计算当前两个人的体重和，特殊处理当左右指针相遇时的情况  
            sum = (l == r) ? people[l] : people[l] + people[r];  
              
            // 如果体重和超过限制，只移动右指针  
            if (sum > limit) {  
                r--;  
            } else {  
                // 如果体重和不超过限制，同时移动左右指针  
                l++;  
                r--;  
            }  
            ans++; // 每次循环代表一艘船  
        }  
          
        return ans; // 返回所需最小船数  
    }  
};  