#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100001;
vector<int> arr(MAXN);
vector<int> help(MAXN);
int n;

// 结果比较大，用int会溢出的，所以返回long long类型
// 特别注意溢出这个点，笔试常见坑
// 返回arr[l...r]范围上，小和的累加和，同时请把arr[l..r]变有序
// 时间复杂度O(n * logn)
long long smallSum(int l, int r) {
    if (l == r) {
        return 0;
    }
    int m = (l + r) / 2;
    return smallSum(l, m) + smallSum(m + 1, r) + merge(l, m, r);
}

// 返回跨左右产生的小和累加和，左侧有序、右侧有序，让左右两侧整体有序
// arr[l...m] arr[m+1...r]
long long merge(int l, int m, int r) {
    long long ans = 0;
    for (int j = m + 1, i = l, sum = 0; j <= r; j++) {
        while (i <= m && arr[i] <= arr[j]) {
            sum += arr[i++];
        }
        ans += sum;
    }
    int i = l, a = l, b = m + 1;
    while (a <= m && b <= r) {
        help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
    }
    while (a <= m) {
        help[i++] = arr[a++];
    }
    while (b <= r) {
        help[i++] = arr[b++];
    }
    for (i = l; i <= r; i++) {
        arr[i] = help[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while (cin >> n && n > 0) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << smallSum(0, n - 1) << endl;
    }
    return 0;
}
