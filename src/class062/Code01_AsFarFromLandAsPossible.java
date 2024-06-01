package class062;

// 可能是单点弹出或整层弹出
// 必须是等权重的才能用bfs,否则必须用djkisjstra
// https://www.bilibili.com/opus/936462793667772439?spm_id_from=333.999.0.0
// 从C和F到Z的最短距离:https://www.bilibili.com/opus/936464850941378583?spm_id_from=333.999.0.0


// 地图分析
// 你现在手里有一份大小为 n x n 的 网格 grid
// 上面的每个 单元格 都用 0 和 1 标记好了其中 0 代表海洋，1 代表陆地。
// 请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的
// 并返回该距离。如果网格上只有陆地或者海洋，请返回 -1。
// 我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：
// (x0, y0) 和 (x1, y1) 这两个单元格之间的距离是 |x0 - x1| + |y0 - y1| 。
// 测试链接 : https://leetcode.cn/problems/as-far-from-land-as-possible/

// 找出海洋单元格，是的距离到陆地单元格的距离最大
// 距离所有陆地最远的海洋是多远：https://www.bilibili.com/opus/936513590270099456?spm_id_from=333.999.0.0
// 所有的2上下左右去扩张3： https://www.bilibili.com/opus/936514221590446097?spm_id_from=333.999.0.0
// n行三列进入格子 https://www.bilibili.com/opus/936515020442828833?spm_id_from=333.999.0.0
public class Code01_AsFarFromLandAsPossible {

	public static int MAXN = 101;

	public static int MAXM = 101;

	public static int[][] queue = new int[MAXN * MAXM][2]; // 数组的方式实现队列

	public static int l, r; // l -> poll, r -> offer

	public static boolean[][] visited = new boolean[MAXN][MAXM];


	// 0:上，1:右，2:下，3:左
	public static int[] move = new int[] { -1, 0, 1, 0, -1 };
	//                                      0  1  2  3   4
	//                                               i
	// i来到0位置 : x + move[i], y + move[i+1] -> x - 1, y 为了向上走
	// i来到1位置 : x + move[i], y + move[i+1] -> x, y + 1 为了向右走
	// i来到2位置 : x + move[i], y + move[i+1] -> x + 1, y 为了向下走
	// i来到3位置 : x + move[i], y + move[i+1] -> x, y - 1 为了向左走
	public static int maxDistance(int[][] grid) {
		l = r = 0; // 队列清空
		int n = grid.length; //行有n行
		int m = grid[0].length; //列有m列
		int seas = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) { //陆地
					visited[i][j] = true;
					queue[r][0] = i; //在i行
					queue[r++][1] = j; //在j列
				} else { //当前是海洋
					visited[i][j] = false;
					seas++;
				}
			}
		}
		if (seas == 0 || seas == n * m) { //海洋为0，或者全是海洋0
			return -1;
		}
		// 注意上面的队列只加入了陆地，海洋没有加入，所以下面最里层的if无需判断grid[nx][ny] == 0
		int level = 0;
		while (l < r) { //队列还有东西
			level++; // 层数+1
			int size = r - l; // 记录队列的长度
			for (int k = 0, x, y, nx, ny; k < size; k++) { // 当前层弹出size次数
				x = queue[l][0];
				y = queue[l++][1];

				for (int i = 0; i < 4; i++) {
					// 上、右、下、左
					nx = x + move[i];
					ny = y + move[i + 1];
					// 无需gird[nx][ny] == 0判断，因为陆地不会加入队列
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
						visited[nx][ny] = true; //标记访问过
						queue[r][0] = nx; //行加入队列
						queue[r++][1] = ny; //列加入队列，r++
					}
				}
			}
		}
		return level - 1; 
	}

}
