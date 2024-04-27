#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXM = 101;
const int MAXT = 1001;

int cost[MAXM];
int val[MAXM];
int dp[MAXT];

int compute1(int n, int t) {
    vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= t; j++) {
            dp[i][j] = dp[i - 1][j]; // not taking item i
            if (j >= cost[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + val[i]); // taking item i
            }
        }
    }
    return dp[n][t];
}

int compute2(int n, int t) {
    vector<int> dp(t + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = t; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
        }
    }
    return dp[t];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    while (cin >> t >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> cost[i] >> val[i];
        }
        cout << compute2(n, t) << "\n";
    }
    return 0;
}
