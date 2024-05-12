#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 5001;
const int mod = 1000000007;
vector<vector<int>> dp(MAXN, vector<int>(MAXN, 0));

// Dynamic programming approach
int ways2(int n, int m) {
    for (int i = 1; i <= n; i++) {
        dp[i][1] = m;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            dp[i][j] = (int)(((long long)dp[i - 1][j] * j) % mod);
            dp[i][j] = (int)((((long long)dp[i - 1][j - 1] * (m - j + 1)) + dp[i][j]) % mod);
        }
    }
    return dp[n][m];
}

int main() {
    // Test cases
    int N = 9;
    int M = 9;
    cout << "Functionality test begins" << endl;
    for (int n = 1; n <= N; n++) {
        for (int m = 1; m <= M; m++) {
            int ans = ways2(n, m);
            cout << "n = " << n << ", m = " << m << ", ways = " << ans << endl;
        }
    }
    cout << "Functionality test ends" << endl;

    // Performance test
    int n = 5000;
    int m = 4877;
    cout << "Performance test begins" << endl;
    cout << "n = " << n << ", m = " << m << endl;
    long start = clock();
    int result = ways2(n, m);
    long end = clock();
    cout << "Result after modulo: " << result << endl;
    cout << "Execution time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;
    cout << "Performance test ends" << endl;

    return 0;
}
