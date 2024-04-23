#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numDecodings(const string& s) {
    int n = s.size();
    const int mod = 1000000007;
    vector<long long> dp(n + 1, 0);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            dp[i] = 0;
        } else {
            dp[i] = (s[i] == '*' ? 9 : 1) * dp[i + 1];
            if (i + 1 < n) {
                if (s[i] != '*') {
                    if (s[i + 1] != '*') {
                        if (stoi(s.substr(i, 2)) <= 26) {
                            dp[i] += dp[i + 2];
                        }
                    } else {
                        if (s[i] == '1') {
                            dp[i] += dp[i + 2] * 9;
                        } else if (s[i] == '2') {
                            dp[i] += dp[i + 2] * 6;
                        }
                    }
                } else {
                    if (s[i + 1] != '*') {
                        dp[i] += dp[i + 2] * (s[i + 1] <= '6' ? 2 : 1);
                    } else {
                        dp[i] += dp[i + 2] * 15;
                    }
                }
            }
            dp[i] %= mod;
        }
    }
    return dp[0];
}

int main() {
    cout << numDecodings("1*") << endl;
    return 0;
}
