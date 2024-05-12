#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000001;
const int OFFSET = 30001;

vector<int> arr(OFFSET + MAXN + OFFSET, 0);

void set_op(int l, int r, int s, int e, int d) {
    arr[l + OFFSET] += s;
    arr[l + 1 + OFFSET] += d - s;
    arr[r + 1 + OFFSET] -= d + e;
    arr[r + 2 + OFFSET] += e;
}

void build(int m) {
    for (int i = 1; i <= m + OFFSET; ++i) {
        arr[i] += arr[i - 1];
    }
    for (int i = 1; i <= m + OFFSET; ++i) {
        arr[i] += arr[i - 1];
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i < n; ++i) {
            int v, x;
            cin >> v >> x;
            set_op(x - 3 * v + 1, x - 2 * v, 1, v, 1);
            set_op(x - 2 * v + 1, x, v - 1, -v, -1);
            set_op(x + 1, x + 2 * v, -v + 1, v, 1);
            set_op(x + 2 * v + 1, x + 3 * v - 1, v - 1, 1, -1);
        }
        build(m);
        cout << arr[OFFSET + 1];
        for (int i = 2; i <= m; ++i) {
            cout << " " << arr[OFFSET + i];
        }
        cout << endl;
    }
    return 0;
}


