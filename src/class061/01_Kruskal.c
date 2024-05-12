#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 5001; // 最大节点数
const int MAXM = 200001; // 最大边数

int father[MAXN]; // 并查集数组
vector<vector<int>> edges(MAXM, vector<int>(3)); // 存储边的信息，每个元素包含起点、终点和权重
int n, m; // 节点数和边数

// 初始化并查集
void build() {
    for (int i = 1; i <= n; ++i) {
        father[i] = i;
    }
}

// 查找并查集中元素的根节点
int find(int i) {
    if (i != father[i]) {
        father[i] = find(father[i]);
    }
    return father[i];
}

// 合并两个集合；如果成功合并返回true，否则返回false
bool union_sets(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        father[fx] = fy;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); // 禁用C和C++标准库之间的同步，提高cin和cout效率
    cin.tie(0); // 解除cin和cout的绑定，进一步提高I/O效率

    while (cin >> n >> m) { // 循环读取每个测试案例
        build(); // 初始化并查集
        for (int i = 0; i < m; ++i) {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2]; // 读取边的信息
        }

        // 使用lambda表达式对边按权重进行排序
        sort(edges.begin(), edges.begin() + m, [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        int ans = 0, edgeCnt = 0; // 初始化最小生成树的权重和已选择的边数
        for (int i = 0; i < m; ++i) {
            if (union_sets(edges[i][0], edges[i][1])) { // 尝试合并两个节点所在的集合
                edgeCnt++; // 成功合并，边数加一
                ans += edges[i][2]; // 累加权重
                if (edgeCnt == n - 1) break; // 如果已选择的边数达到n-1，提前结束循环
            }
        }
        cout << (edgeCnt == n - 1 ? ans : -1) << "\n"; // 输出结果，若未形成最小生成树输出-1
    }

    return 0;
}
