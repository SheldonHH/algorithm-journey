#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Code03_StaticSpace {
public:
    static const int MAXN = 201; // Maximum rows
    static const int MAXM = 201; // Maximum columns

    // 2D matrix space, statically allocated
    static int mat[MAXN][MAXM];

    // Helper array, statically allocated
    static int arr[MAXM];

    static int n, m; // Dimensions of the current test matrix

    static int maxSumSubarray() {
        int max = INT_MIN;
        int cur = 0;
        for (int i = 0; i < m; i++) {
            cur += arr[i];
            max = std::max(max, cur);
            if (cur < 0) {
                cur = 0;
            }
        }
        return max;
    }

    static int maxSumSubmatrix() {
        int max = INT_MIN;
        for (int i = 0; i < n; i++) {
            fill(arr, arr + m, 0); // Clear the helper array
            for (int j = i; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    arr[k] += mat[j][k];
                }
                max = std::max(max, maxSumSubarray());
            }
        }
        return max;
    }

    static void solve() {
        ios::sync_with_stdio(false); // Disable sync
        cin.tie(nullptr); // Untie cin and cout
        cout.tie(nullptr); // Faster I/O

        while (cin >> n >> m) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cin >> mat[i][j];
                }
            }
            cout << maxSumSubmatrix() << "\n";
        }
        cout.flush(); // Flush the output buffer
    }
};

// Initialize static variables
int Code03_StaticSpace::mat[Code03_StaticSpace::MAXN][Code03_StaticSpace::MAXM];
int Code03_StaticSpace::arr[Code03_StaticSpace::MAXM];
int Code03_StaticSpace::n = 0;
int Code03_StaticSpace::m = 0;

int main() {
    Code03_StaticSpace::solve();
    return 0;
}
