package class048;

// 利用二维前缀和信息迅速得到二维区域和
// 测试链接 : https://leetcode.cn/problems/range-sum-query-2d-immutable/
public class Code01_PrefixSumMatrix {

	class NumMatrix {

		public int[][] sum;

		public NumMatrix(int[][] matrix) {
			int n = matrix.length;
			int m = matrix[0].length;
			sum = new int[n + 1][m + 1];
			for (int a = 1, b = 0; b < n; a++, b++) {
				for (int c = 1, d = 0; d < m; c++, d++) {
					sum[a][c] = matrix[b][d];
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
				}
			}
		}

		public int sumRegion(int row1, int col1, int row2, int col2) {
			row2++;
			col2++;
			return sum[row2][col2] - sum[row2][col1] - sum[row1][col2] + sum[row1][col1];
		}

	}

}
