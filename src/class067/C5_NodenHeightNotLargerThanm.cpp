#include <iostream>
#include <vector>

// 常量定义
const int MAXN = 51;
const int MOD = 1000000007;

// 动态规划数组
std::vector<std::vector<long long>> dp1(MAXN, std::vector<long long>(MAXN, -1));
std::vector<std::vector<long long>> dp2(MAXN, std::vector<long long>(MAXN, 0));
std::vector<long long> dp3(MAXN, 0);

// 计算具有n个节点且高度不超过m的二叉树的数量
// 记忆化搜索
int compute1(int n, int m) {
    if (n == 0) return 1;
    if (m == 0) return 0;
    if (dp1[n][m] != -1) return dp1[n][m];

    long long ans = 0;
    for (int k = 0; k < n; k++) {
        ans = (ans + ((long long) compute1(k, m - 1) * compute1(n - k - 1, m - 1)) % MOD) % MOD;
    }
    dp1[n][m] = ans;
    return (int) ans;
}

// 严格位置依赖的动态规划
int compute2(int n, int m) {
    for (int j = 0; j <= m; j++) {
        dp2[0][j] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp2[i][j] = 0;
            for (int k = 0; k < i; k++) {
                dp2[i][j] = (dp2[i][j] + dp2[k][j - 1] * dp2[i - k - 1][j - 1] % MOD) % MOD;
            }
        }
    }
    return (int) dp2[n][m];
}

// 空间压缩版本
int compute3(int n, int m) {
    dp3[0] = 1;
    for (int j = 1; j <= m; j++) {
        for (int i = n; i >= 1; i--) {
            dp3[i] = 0;
            for (int k = 0; k < i; k++) {
                dp3[i] = (dp3[i] + dp3[k] * dp3[i - k - 1] % MOD) % MOD;
            }
        }
    }
    return (int) dp3[n];
}

int main() {
    std::ios::sync_with_stdio(false); // 加速cin和cout
    int n, m;
    while (std::cin >> n >> m) {
        std::cout << compute3(n, m) << std::endl;
    }
    return 0;
}
