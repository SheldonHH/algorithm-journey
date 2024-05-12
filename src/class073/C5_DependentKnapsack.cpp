#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 33001;
const int MAXM = 61;

int cost[MAXM];
int val[MAXM];
int king[MAXM]; // To indicate if the item is a main item (0 for attachments)
vector<int> attachment[MAXM];
int dp[MAXN];

// To handle the dependencies and perform the knapsack calculation
int compute() {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= MAXM; i++) {
        if (king[i]) { // Check if it's a main item
            for (int j = MAXN - cost[i]; j >= 0; j--) {
                dp[j + cost[i]] = max(dp[j + cost[i]], dp[j] + val[i]); // Take the main item
                for (int a : attachment[i]) {
                    if (j + cost[i] + cost[a] <= MAXN) {
                        dp[j + cost[i] + cost[a]] = max(dp[j + cost[i] + cost[a]], dp[j] + val[i] + val[a]); // Take main item and one attachment
                    }
                }
                if (attachment[i].size() == 2) {
                    int a = attachment[i][0], b = attachment[i][1];
                    if (j + cost[i] + cost[a] + cost[b] <= MAXN) {
                        dp[j + cost[i] + cost[a] + cost[b]] = max(dp[j + cost[i] + cost[a] + cost[b]], dp[j] + val[i] + val[a] + val[b]); // Take main item and both attachments
                    }
                }
            }
        }
    }
    return dp[MAXN - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m; // Total money and number of items
    memset(king, 0, sizeof(king));
    for (int i = 1, v, p, q; i <= m; i++) {
        cin >> v >> p >> q;
        cost[i] = v;
        val[i] = v * p;
        if (q == 0) {
            king[i] = 1;
        } else {
            attachment[q].push_back(i); // Add this item as an attachment to its main item
        }
    }

    cout << compute() << endl;
    return 0;
}
