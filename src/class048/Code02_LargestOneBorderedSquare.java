package class048;

// 边框为1的最大正方形
// 给你一个由若干 0 和 1 组成的二维网格 grid
// 请你找出边界全部由 1 组成的最大 正方形 子网格
// 并返回该子网格中的元素数量。如果不存在，则返回 0。
// 测试链接 : https://leetcode.cn/problems/largest-1-bordered-square/
// 打败比例不高，但完全是常数时间的问题
// 本文件的实现，时间复杂度O(n * m * min(n,m))，额外空间复杂度O(1)
// 追求复杂度指标上的绝对最优解
public class Code02_LargestOneBorderedSquare {

	public static int largest1BorderedSquare(int[][] g) {
		int n = g.length;
		int m = g[0].length;
		build(n, m, g);
		if (sum(g, 0, 0, n - 1, m - 1) == 0) {
			return 0;
		}
		int ans = 1;
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < m; b++) {
				for (int c = a + ans, d = b + ans, k = ans + 1; c < n && d < m; c++, d++, k++) {
					if (sum(g, a, b, c, d) - sum(g, a + 1, b + 1, c - 1, d - 1) == (k - 1) << 2) {
						ans = k;
					}
				}
			}
		}
		return ans * ans;
	}

	public static void build(int n, int m, int[][] g) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				g[i][j] += get(g, i, j - 1) + get(g, i - 1, j) - get(g, i - 1, j - 1);
			}
		}
	}

	public static int sum(int[][] g, int a, int b, int c, int d) {
		return a > c ? 0 : (g[c][d] - get(g, c, b - 1) - get(g, a - 1, d) + get(g, a - 1, b - 1));
	}

	public static int get(int[][] g, int i, int j) {
		return (i < 0 || j < 0) ? 0 : g[i][j];
	}

}
