#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100001;
int arr[MAXN];
int right[MAXN];
int ends[MAXN];
int n, k;

// Binary search for the longest non-increasing subsequence
int bs1(int len, int num) {
    int l = 0, r = len - 1, m, ans = -1;
    while (l <= r) {
        m = (l + r) / 2;
        if (ends[m] < num) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}

// Binary search for the longest non-decreasing subsequence
int bs2(int len, int num) {
    int l = 0, r = len - 1, m, ans = -1;
    while (l <= r) {
        m = (l + r) / 2;
        if (ends[m] > num) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}

// Calculates the right array which represents the length of the longest non-decreasing subsequence starting from each index
void calculateRight() {
    int len = 0;
    for (int i = n - 1; i >= 0; i--) {
        int find = bs1(len, arr[i]);
        if (find == -1) {
            ends[len++] = arr[i];
            right[i] = len;
        } else {
            ends[find] = arr[i];
            right[i] = find + 1;
        }
    }
}

int compute() {
    calculateRight();
    int len = 0;
    int ans = 0;
    for (int i = 0, j = k; j < n; i++, j++) {
        int find = bs2(len, arr[j]);
        int left = find == -1 ? len : find;
        ans = max(ans, left + k + right[j]);
        find = bs2(len, arr[i]);
        if (find == -1) {
            ends[len++] = arr[i];
        } else {
            ends[find] = arr[i];
        }
    }
    ans = max(ans, len + k);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (cin >> n >> k) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        if (k >= n) {
            cout << n << "\n";
        } else {
            cout << compute() << "\n";
        }
    }
    return 0;
}
