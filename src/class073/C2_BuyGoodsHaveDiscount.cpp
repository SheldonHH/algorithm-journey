#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 501;
const int MAXX = 100001;

int cost[MAXN];
long long val[MAXN];
long long dp[MAXX];

int n, m, x;

long long compute() {
    fill(dp, dp + x + 1, 0);
    for (int i = 1; i < m; i++) {
        for (int j = x; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
        }
    }
    return dp[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> x) {
        m = 1;
        long long ans = 0;
        long long happy = 0;
        for (int i = 0, pre, cur, well; i < n; i++) {
            cin >> pre >> cur >> happy;
            well = pre - cur - cur;
            if (well >= 0) {
                x += well;
                ans += happy;
            } else {
                cost[m] = -well;
                val[m++] = happy;
            }
        }
        ans += compute();
        cout << ans << "\n";
    }
    return 0;
}
