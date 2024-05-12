#include <iostream>
#include <vector>
using namespace std;

// Function to build a prefix sum matrix for a given matrix m
void build(vector<vector<int>>& m) {
    for (int i = 1; i < m.size(); ++i) {
        for (int j = 1; j < m[0].size(); ++j) {
            m[i][j] += m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1];
        }
    }
}

// Function to compute the sum of a subregion within the prefix sum matrix
int sumRegion(const vector<vector<int>>& sum, int a, int b, int c, int d) {
    return sum[c][d] - sum[c][b - 1] - sum[a - 1][d] + sum[a - 1][b - 1];
}

// Function to modify the difference matrix for a given stamp area
void add(vector<vector<int>>& diff, int a, int b, int c, int d) {
    diff[a][b] += 1;
    diff[c + 1][d + 1] += 1;
    diff[c + 1][b] -= 1;
    diff[a][d + 1] -= 1;
}

// Function to check if it's possible to stamp grid with stamp of dimensions h*w
bool possibleToStamp(vector<vector<int>> grid, int h, int w) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    
    // Initialize prefix sum matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum[i + 1][j + 1] = grid[i][j];
        }
    }
    build(sum);

    // Initialize the difference matrix
    vector<vector<int>> diff(n + 2, vector<int>(m + 2, 0));
    
    // Process each potential stamp area
    for (int a = 1, c = a + h - 1; c <= n; ++a, ++c) {
        for (int b = 1, d = b + w - 1; d <= m; ++b, ++d) {
            // If the area is completely empty, add the stamp
            if (sumRegion(sum, a, b, c, d) == 0) {
                add(diff, a, b, c, d);
            }
        }
    }

    // Build the difference matrix
    build(diff);

    // Check each cell in the original grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // If there is a hole in the original grid that is not covered by a stamp, return false
            if (grid[i][j] == 0 && diff[i + 1][j + 1] == 0) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    // Sample input
    vector<vector<int>> grid = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };
    int stampHeight = 2;
    int stampWidth = 2;

    // Call the function and output the result
    cout << (possibleToStamp(grid, stampHeight, stampWidth) ? "true" : "false") << endl;
    return 0;
}
