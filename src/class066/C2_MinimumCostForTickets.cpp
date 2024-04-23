#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> durations = {1, 7, 30};  // 三种票的有效期限

    // 递归方式求解最小票价
    int mincostTickets1(vector<int>& days, vector<int>& costs) {
        function<int(int)> f1 = [&](int i) -> int {
            if (i == days.size()) return 0;
            int ans = INT_MAX;
            for (int k = 0; k < 3; ++k) {
                int j = i;
                while (j < days.size() && days[i] + durations[k] > days[j]) {
                    j++;
                }
                ans = min(ans, costs[k] + f1(j));
            }
            return ans;
        };
        return f1(0);
    }

    // 使用记忆化搜索的递归方式
    int mincostTickets2(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), INT_MAX);
        function<int(int)> f2 = [&](int i) -> int {
            if (i == days.size()) return 0;
            if (dp[i] != INT_MAX) return dp[i];
            int ans = INT_MAX;
            for (int k = 0; k < 3; ++k) {
                int j = i;
                while (j < days.size() && days[i] + durations[k] > days[j]) {
                    j++;
                }
                ans = min(ans, costs[k] + f2(j));
            }
            dp[i] = ans;
            return ans;
        };
        return f2(0);
    }

    // 使用动态规划自底向上方法求解
    int mincostTickets3(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int k = 0; k < 3; ++k) {
                int j = i;
                while (j < days.size() && days[i] + durations[k] > days[j]) {
                    j++;
                }
                dp[i] = min(dp[i], costs[k] + dp[j]);
            }
        }
        return dp[0];
    }
};

int main() {
    Solution solution;
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};
    cout << "mincostTickets1: " << solution.mincostTickets1(days, costs) << endl;
    cout << "mincostTickets2: " << solution.mincostTickets2(days, costs) << endl;
    cout << "mincostTickets3: " << solution.mincostTickets3(days, costs) << endl;
    return 0;
}
