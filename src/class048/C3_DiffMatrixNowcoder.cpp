#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1005;
const int MAXM = 1005;
long long diff[MAXN][MAXM];

void add(int a, int b, int c, int d, int k) {
    diff[a][b] += k;
    diff[c + 1][b] -= k;
    diff[a][d + 1] -= k;
    diff[c + 1][d + 1] += k;
}

void build(int n, int m) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }
}

void clear(int n, int m) {
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 1; j <= m + 1; ++j) {
            diff[i][j] = 0;
        }
    }
}

int main() {
    int n, m, q;
    while (cin >> n >> m >> q) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int val;
                cin >> val;
                add(i, j, i, j, val);
            }
        }
        
        for (int i = 1; i <= q; ++i) {
            int a, b, c, d, k;
            cin >> a >> b >> c >> d >> k;
            add(a, b, c, d, k);
        }

        build(n, m);

        for (int i = 1; i <= n; ++i) {
            cout << diff[i][1];
            for (int j = 2; j <= m; ++j) {
                cout << " " << diff[i][j];
            }
            cout << endl;
        }

        clear(n, m);
    }
    return 0;
}
