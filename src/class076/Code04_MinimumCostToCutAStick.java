package class076;

import java.util.Arrays;

// 切棍子的最小成本
// 有一根长度为n个单位的木棍，棍上从0到n标记了若干位置
// 给你一个整数数组cuts，其中cuts[i]表示你需要将棍子切开的位置
// 你可以按顺序完成切割，也可以根据需要更改切割的顺序
// 每次切割的成本都是当前要切割的棍子的长度，切棍子的总成本是历次切割成本的总和
// 对棍子进行切割将会把一根木棍分成两根较小的木棍
// 这两根木棍的长度和就是切割前木棍的长度
// 返回切棍子的最小总成本
// 测试链接 : https://leetcode.cn/problems/minimum-cost-to-cut-a-stick/

// n=8的时候，总长度是8，9个端点
// 一定是(0,8)左开右开的
// 1-n-1范围上的值
// cuts[4,6,2] ，切顺序无所谓
// 先切2，先吃8： 左侧长度为2，右侧长度为6
// 切4: 吃6： 左2，右4
// 切6：吃4
// 18代价

// （吃=承担多少代价）
// 方法2 
// 切4: 吃6： 左4，右4
// 切2: 吃4
// 切6: 吃4
// https://www.bilibili.com/opus/935737253416665097?spm_id_from=333.999.0.0


// cuts: [2,4,6]
// arr:  [0,2,4,6,8]
// 最左侧补0，最右侧补充n长度，然后把cuts抄到下标123上
// https://www.bilibili.com/opus/935739091658473495?spm_id_from=333.999.0.0

// 核心思路：R+1的数值 - (L-1)位置的数 两者一减
// 8-0=8
// 8-2=6
// https://www.bilibili.com/opus/935740302830862341?spm_id_from=333.999.0.0

// 尝试以每一个切点做那一刀

public class Code04_MinimumCostToCutAStick {

	// 记忆化搜索
	public static int minCost1(int n, int[] cuts) {
		int m = cuts.length;
		Arrays.sort(cuts);
		// n = 3000
		// 14 100 1009 2008
		// 0  1	  2    3
		// 0  14  100  1009 2008 3000
		// 0  1   2    3    4    5

		// 前面补0， 后面补n
		int[] arr = new int[m + 2];
		arr[0] = 0;
		for (int i = 1; i <= m; ++i) {
			arr[i] = cuts[i - 1];
		}
		arr[m + 1] = n;
		int[][] dp = new int[m + 2][m + 2];
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = -1;
			}
		}
		return f(arr, 1, m, dp); //调用1-m上
	}
	
	// 切点[l....r]，决定一个顺序
	// 让切点都切完，总代价最小
	public static int f(int[] arr, int l, int r, int[][] dp) {
		if (l > r) { //没切点
			return 0;
		}
		if (l == r) { // 只剩一个切点，一个总长度
			return arr[r + 1] - arr[l - 1];
		}
		if (dp[l][r] != -1) {
			return dp[l][r];
		}
		int ans = Integer.MAX_VALUE;
		for (int k = l; k <= r; k++) { //枚举切点
			ans = Math.min(ans, f(arr, l, k - 1, dp) + f(arr, k + 1, r, dp));
		}
		ans += arr[r + 1] - arr[l - 1]; // 加上第一下的切点
		dp[l][r] = ans;
		return ans;
	}

	// 严格位置依赖的动态规划
	// 任何一个普遍的格子，需要左侧和下侧：https://www.bilibili.com/opus/935760257261502499?spm_id_from=333.999.0.0
	public static int minCost2(int n, int[] cuts) {
		int m = cuts.length;
		Arrays.sort(cuts); // 切点排序
		//
		int[] arr = new int[m + 2];
		arr[0] = 0;
		for (int i = 1; i <= m; ++i) { // 
			arr[i] = cuts[i - 1];
		}
		arr[m + 1] = n;
		int[][] dp = new int[m + 2][m + 2];
		for (int i = 1; i <= m; i++) {
			dp[i][i] = arr[i + 1] - arr[i - 1]; /
		}
		for (int l = m - 1, next; l >= 1; l--) {
			for (int r = l + 1; r <= m; r++) {
				next = Integer.MAX_VALUE;
				for (int k = l; k <= r; k++) {
					next = Math.min(next, dp[l][k - 1] + dp[k + 1][r]);
				}
				dp[l][r] = arr[r + 1] - arr[l - 1] + next;
			}
		}
		return dp[1][m]; // 递归函数怎么调，就怎么返回
	}

}
