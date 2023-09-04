#include <iostream>
#include <vector>
using namespace std;

// Calculate prefix sum for the given grid.
void build(int n, int m, vector<vector<int>>& g) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            g[i][j] += (i > 0 ? g[i - 1][j] : 0) + (j > 0 ? g[i][j - 1] : 0) - (i > 0 && j > 0 ? g[i - 1][j - 1] : 0);
        }
    }
}

// Fetch the value from grid safely, return 0 if out of bounds.
int get(vector<vector<int>>& g, int i, int j) {
    return (i < 0 || j < 0) ? 0 : g[i][j];
}

// Compute the sum for the subgrid [a, b] to [c, d].
int sum(vector<vector<int>>& g, int a, int b, int c, int d) {
    return a > c ? 0 : (g[c][d] - get(g, c, b - 1) - get(g, a - 1, d) + get(g, a - 1, b - 1));
}

// Function to find largest 1-bordered square in the grid.
int largest1BorderedSquare(vector<vector<int>>& g) {
    int n = g.size();
    int m = g[0].size();
    build(n, m, g);

    // Check if grid contains at least one '1'.
    if (sum(g, 0, 0, n - 1, m - 1) == 0) {
        return 0;
    }

    // Initially, largest square side length.
    int ans = 1;

    // Loop through each possible top-left corner (a, b) of square.
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < m; ++b) {
            // Loop through possible bottom-right corner (c, d) of square with side length greater than 'ans'.
            for (int c = a + ans, d = b + ans, k = ans + 1; c < n && d < m; ++c, ++d, ++k) {
                // Check if the square is valid.
                if (sum(g, a, b, c, d) - sum(g, a + 1, b + 1, c - 1, d - 1) == ((k - 1) << 2)) {
                    ans = k;
                }
            }
        }
    }

    // Return area of largest square.
    return ans * ans;
}

int main() {
    // Sample grid
    vector<vector<int>> grid = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1},
    };

    // Find largest 1-bordered square
    cout << largest1BorderedSquare(grid) << endl;

    return 0;
}
≈