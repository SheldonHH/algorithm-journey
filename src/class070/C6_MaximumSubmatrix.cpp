#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Code06_MaximumSubmatrix {
public:
    static vector<int> getMaxMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxSum = INT_MIN;
        vector<int> result(4); // To store the coordinates (a, b, c, d)
        vector<int> nums(m);
        for (int up = 0; up < n; ++up) {
            fill(nums.begin(), nums.end(), 0);
            for (int down = up; down < n; ++down) {
                int pre = INT_MIN;
                for (int l = 0, r = 0; r < m; ++r) {
                    nums[r] += grid[down][r];
                    if (pre >= 0) {
                        pre += nums[r];
                    } else {
                        pre = nums[r];
                        l = r;
                    }
                    if (pre > maxSum) {
                        maxSum = pre;
                        result[0] = up;    // Top row of the submatrix
                        result[1] = l;     // Left column of the submatrix
                        result[2] = down;  // Bottom row of the submatrix
                        result[3] = r;     // Right column of the submatrix
                    }
                }
            }
        }
        return result;
    }
};
