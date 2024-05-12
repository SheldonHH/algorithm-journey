#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Sorts the array and removes duplicate elements. Returns the new size.
int sortUnique(vector<long long> &nums) {
    sort(nums.begin(), nums.end());
    int unique_size = unique(nums.begin(), nums.end()) - nums.begin();
    return unique_size;
}

// Finds the rank of a given value 'v' in the sorted array 'nums'
int rank(const vector<long long> &nums, long long v, int size) {
    return lower_bound(nums.begin(), nums.begin() + size, v) - nums.begin() + 1;
}

// 2D difference operation
void add(vector<vector<int>> &diff, int a, int b, int c, int d) {
    diff[a][b]++;
    diff[c + 1][d + 1]++;
    diff[c + 1][b]--;
    diff[a][d + 1]--;
}

// Main function to find the field with the greatest blessing
int fieldOfGreatestBlessing(vector<vector<int>> fields) {
    int n = fields.size();
    vector<long long> xs(2 * n), ys(2 * n);

    // Extract the coordinates and dimensions into xs and ys
    for (int i = 0; i < n; ++i) {
        long long x = fields[i][0], y = fields[i][1], r = fields[i][2];
        xs[2 * i] = (x << 1) - r;
        xs[2 * i + 1] = (x << 1) + r;
        ys[2 * i] = (y << 1) - r;
        ys[2 * i + 1] = (y << 1) + r;
    }

    // Sort and find the unique elements
    int sizex = sortUnique(xs);
    int sizey = sortUnique(ys);

    vector<vector<int>> diff(sizex + 2, vector<int>(sizey + 2, 0));

    // Populate the difference array
    for (int i = 0; i < n; ++i) {
        long long x = fields[i][0], y = fields[i][1], r = fields[i][2];
        int a = rank(xs, (x << 1) - r, sizex);
        int b = rank(ys, (y << 1) - r, sizey);
        int c = rank(xs, (x << 1) + r, sizex);
        int d = rank(ys, (y << 1) + r, sizey);
        add(diff, a, b, c, d);
    }

    // Compute the field strength
    int ans = 0;
    for (int i = 1; i < diff.size(); ++i) {
        for (int j = 1; j < diff[0].size(); ++j) {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            ans = max(ans, diff[i][j]);
        }
    }

    return ans;
}

int main() {
    // Sample test case: fields = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}}
    vector<vector<int>> fields = {
        {1, 1, 1},
        {2, 2, 2},
        {3, 3, 3}
    };

    int result = fieldOfGreatestBlessing(fields);
    cout << "The field with the greatest blessing has a strength of: " << result << endl;

    return 0;
}
