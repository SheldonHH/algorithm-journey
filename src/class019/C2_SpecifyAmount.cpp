#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN
using namespace std;

class Code02_SpecifyAmount {
public:
    static int maxSumSubmatrix(const vector<vector<int>>& mat, int n, int m) {
        int max = INT_MIN;
        for (int i = 0; i < n; i++) {
            vector<int> arr(m, 0);
            for (int j = i; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    arr[k] += mat[j][k];
                }
                max = std::max(max, maxSumSubarray(arr, m));
            }
        }
        return max;
    }

    static int maxSumSubarray(const vector<int>& arr, int m) {
        int max = INT_MIN;
        int cur = 0;
        for (int i = 0; i < m; i++) {
            cur += arr[i];
            max = std::max(max, cur);
            if (cur < 0) cur = 0;
        }
        return max;
    }

    static void process() {
        int n, m;
        while (cin >> n >> m) {
            vector<vector<int>> mat(n, vector<int>(m));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cin >> mat[i][j];
                }
            }
            cout << maxSumSubmatrix(mat, n, m) << endl;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);  // Speed up cin/cout.
    cin.tie(NULL);                // Untie cin from cout.
    Code02_SpecifyAmount::process();
    return 0;
}
