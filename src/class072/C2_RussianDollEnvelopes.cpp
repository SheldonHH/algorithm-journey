#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 俄罗斯套娃信封问题
// 给你一个二维整数数组envelopes ，其中envelopes[i]=[wi, hi]
// 表示第 i 个信封的宽度和高度
// 当另一个信封的宽度和高度都比这个信封大的时候
// 这个信封就可以放进另一个信封里，如同俄罗斯套娃一样
// 请计算 最多能有多少个信封能组成一组“俄罗斯套娃”信封
// 即可以把一个信封放到另一个信封里面，注意不允许旋转信封
class RussianDollEnvelopes {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // 排序策略:
        // 宽度从小到大
        // 宽度一样，高度从大到小
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] != b[0] ? a[0] < b[0] : b[1] < a[1];
        });
        vector<int> ends(n);
        int len = 0;
        for (int i = 0; i < n; i++) {
            int num = envelopes[i][1];
            int find = bs(ends, len, num);
            if (find == -1) {
                ends[len++] = num;
            } else {
                ends[find] = num;
            }
        }
        return len;
    }

private:
    int bs(vector<int>& ends, int len, int num) {
        int l = 0, r = len - 1, ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (ends[m] >= num) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};

