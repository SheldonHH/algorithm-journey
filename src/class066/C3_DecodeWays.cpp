#include <iostream>
#include <vector>
#include <string>

using namespace std;


// Recursive approach
int num_decodings1(const  string& s, int i = 0) {
    if (i == s.size()) return 1;
    if (s[i] == '0') return 0;
    int ans = num_decodings1(s, i + 1);
    if (i + 1 < s.size() &&  stoi(s.substr(i, 2)) <= 26) {
        ans += num_decodings1(s, i + 2);
    }
    return ans;
}

// Recursive with memoization
int helper2(const  string& s, int i,  vector<int>& dp) {
    if (i == s.size()) return 1;
    if (dp[i] != -1) return dp[i];
    int ans = 0;
    if (s[i] != '0') {
        ans = helper2(s, i + 1, dp);
        if (i + 1 < s.size() &&  stoi(s.substr(i, 2)) <= 26) {
            ans += helper2(s, i + 2, dp);
        }
    }
    dp[i] = ans;
    return ans;
}

int num_decodings2(const  string& s) {
     vector<int> dp(s.size(), -1);
    return helper2(s, 0, dp);
}

// Dynamic programming approach
int num_decodings3(const  string& s) {
    int n = s.size();
     vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            dp[i] = 0;
        } else {
            dp[i] = dp[i + 1];
            if (i + 1 < n &&  stoi(s.substr(i, 2)) <= 26) {
                dp[i] += dp[i + 2];
            }
        }
    }
    return dp[0];
}

// Dynamic programming with space optimization
int num_decodings4(const  string& s) {
    int next = 1;
    int next_next = 0;
    int cur = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '0') {
            cur = 0;
        } else {
            cur = next;
            if (i + 1 < s.size() &&  stoi(s.substr(i, 2)) <= 26) {
                cur += next_next;
            }
        }
        next_next = next;
        next = cur;
    }
    return next;
}

// Example usage
int main() {
     string s = "11106";
     cout << "Recursive: " << num_decodings1(s) <<  endl;
     cout << "Recursive with memoization: " << num_decodings2(s) <<  endl;
     cout << "Dynamic programming: " << num_decodings3(s) <<  endl;
     cout << "Space optimized dynamic programming: " << num_decodings4(s) <<  endl;
    return 0;
}
