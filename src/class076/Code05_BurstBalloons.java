package class076;

// 戳气球
// 有 n 个气球，编号为0到n-1，每个气球上都标有一个数字，这些数字存在数组nums中
// 现在要求你戳破所有的气球。戳破第 i 个气球
// 你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币
// 这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号
// 如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球
// 求所能获得硬币的最大数量
// 测试链接 : https://leetcode.com/problems/burst-balloons/

// 左右因子都认为是1
// https://www.bilibili.com/opus/935761657437618195?spm_id_from=333.999.0.0
public class Code05_BurstBalloons {
	// 右侧理我最近的气球不一定是D,所以按照气球最先打爆不行：https://www.bilibili.com/opus/935762881482326036?spm_id_from=333.999.0.0
	// 记忆化搜索
	// arr[l...r]范围上，气球决定一个顺序得到最大得分返回
	public static int maxCoins1(int[] nums) { // 递归的解
		int n = nums.length;
		// 左右补充1 
		// a b c d e
		// 1 a b c d e 1
		int[] arr = new int[n + 2];
		arr[0] = 1;
		arr[n + 1] = 1;
		for (int i = 0; i < n; i++) {
			arr[i + 1] = nums[i];
		}
		int[][] dp = new int[n + 2][n + 2];
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				dp[i][j] = -1;
			}
		}
		return f(arr, 1, n, dp);
	}

	// arr[l...r]这些气球决定一个顺序，获得最大得分返回！
	// 一定有 : arr[l-1]一定没爆！
	// 一定有 : arr[r+1]一定没爆！
	// 尝试每个气球最后打爆 最后最后

	// 来到l...r范围上时候，递归展开才好做，潜台词必须是l-1,和r+1的位置必须必须没爆
	// https://www.bilibili.com/opus/935764402152407062?spm_id_from=333.999.0.0
	public static int f(int[] arr, int l, int r, int[][] dp) { // O(n^2) O(n^3)
		if (dp[l][r] != -1) {
			return dp[l][r];
		}
		int ans;
		if (l == r) {
			// x 就一个爷的情况
			// l 
			ans = arr[l - 1] * arr[l] * arr[r + 1];
		} else {
			// l   ....r
			// l +1 +2 .. r
			ans = Math.max(
					arr[l - 1] * arr[l] * arr[r + 1] + f(arr, l + 1, r, dp), // l位置的气球最后打爆
					arr[l - 1] * arr[r] * arr[r + 1] + f(arr, l, r - 1, dp));// r位置的气球最后打爆
			for (int k = l + 1; k < r; k++) { // 上面是两个端点，下面是内部l+1🔪r
				// k位置的气球最后打爆
				// l...k-1  k  k+1...r
				ans = Math.max(ans, arr[l - 1] * arr[k] * arr[r + 1] + f(arr, l, k - 1, dp) + f(arr, k + 1, r, dp));
			}
		}
		dp[l][r] = ans;
		return ans;
	}

	// 严格位置依赖的动态规划
	public static int maxCoins2(int[] nums) {
		int n = nums.length;
		int[] arr = new int[n + 2];
		arr[0] = 1;
		arr[n + 1] = 1;
		for (int i = 0; i < n; i++) {
			arr[i + 1] = nums[i];
		}
		int[][] dp = new int[n + 2][n + 2];
		for (int i = 1; i <= n; i++) {
			dp[i][i] = arr[i - 1] * arr[i] * arr[i + 1];
		}
		for (int l = n, ans; l >= 1; l--) {
			for (int r = l + 1; r <= n; r++) {
				ans = Math.max(arr[l - 1] * arr[l] * arr[r + 1] + dp[l + 1][r],
						arr[l - 1] * arr[r] * arr[r + 1] + dp[l][r - 1]);
				for (int k = l + 1; k < r; k++) {
					ans = Math.max(ans, arr[l - 1] * arr[k] * arr[r + 1] + dp[l][k - 1] + dp[k + 1][r]);
				}
				dp[l][r] = ans;
			}
		}
		return dp[1][n];
	}

}
