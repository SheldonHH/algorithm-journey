package class070;

// 打家劫舍 IV
// 沿街有一排连续的房屋。每间房屋内都藏有一定的现金
// 现在有一位小偷计划从这些房屋中窃取现金
// 由于相邻的房屋装有相互连通的防盗系统，所以小偷不会窃取相邻的房屋
// 小偷的 窃取能力 定义为他在窃取过程中能从单间房屋中窃取的 最大金额
// 给你一个整数数组 nums 表示每间房屋存放的现金金额
// 第i间房屋中放有nums[i]的钱数
// 另给你一个整数k，表示小偷需要窃取至少 k 间房屋
// 返回小偷需要的最小窃取能力值
// 测试链接 : https://leetcode.cn/problems/house-robber-iv/
// https://leetcode.com/problems/house-robber-iv/solutions/5225476/topic/
public class Code05_HouseRobberIV {
	// 能力值至少至少至少 定多少能让小偷偷至少k间房屋，在不能选择相邻房屋的情况下，还必须至少偷够k间房屋
	public static int minCapability(int[] nums, int k) { //二分答案法建立单调性
	// 能力的上限定为房屋最大额绝对够用，一直二分下去，直到找到最小的能力值偷够k间
	// 
	// 具有单调性：能力越大越好办事，能力越大，偷的房屋数越多
		int n = nums.length, l = nums[0], r = nums[0];
		for (int i = 1; i < n; i++) {
			l = Math.min(l, nums[i]);
			r = Math.max(r, nums[i]);
		}
		// l....r 能力范围需要搜索的范围
		int m, ans = 0;
		while (l <= r) {
			m = (l + r) / 2;
			if (mostRob1(nums, n, m) >= k) { // n长度，当能力是m的时候
				ans = m; //记录一个达标的能力
				r = m - 1; //右边放弃掉，去左侧找还有没有尽量小的能力
			} else {
				l = m + 1;
			}
		}
		return ans;
	}

	// 盗贼能力为ability时
	// 返回盗贼最多能窃取多少间房屋
	// 注意限制 : 不能窃取相邻房屋
	public static int mostRob1(int[] nums, int n, int ability) {
		if (n == 1) { // 只有一个房屋
			return nums[0] <= ability ? 1 : 0; 
		}
		if (n == 2) { // 有两个房屋
			// 只要有一个小于等于能力，就能偷1间房屋
			return (nums[0] <= ability || nums[1] <= ability) ? 1 : 0;
		}
		int[] dp = new int[n];
		dp[0] = nums[0] <= ability ? 1 : 0;
		dp[1] = (nums[0] <= ability || nums[1] <= ability) ? 1 : 0;
		for (int i = 2; i < n; i++) {
			// i放弃，i能偷，则偷i-2
			dp[i] = Math.max(dp[i - 1], (nums[i] <= ability ? 1 : 0) + dp[i - 2]);
		}
		return dp[n - 1];
	}

	// 继续空间压缩优化
	public static int mostRob2(int[] nums, int n, int ability) {
		if (n == 1) {
			return nums[0] <= ability ? 1 : 0;
		}
		if (n == 2) {
			return (nums[0] <= ability || nums[1] <= ability) ? 1 : 0;
		}
		int prepre = nums[0] <= ability ? 1 : 0; // dp[0]
		int pre = (nums[0] <= ability || nums[1] <= ability) ? 1 : 0; // dp[1]
		for (int i = 2, cur; i < n; i++) {
			cur = Math.max(pre, (nums[i] <= ability ? 1 : 0) + prepre);
			prepre = pre; 
			pre = cur;
		}
		return pre;
	}

	// 继续贪心优化常数变量，因为核心是为了求最多能偷多少间房屋，而不是具体的偷哪些房屋
	// 收益实际上是+1，所以只要nums[i] <= ability，就可以偷 https://leetcode.com/problems/house-robber-iv/post-solution/5225476/
	public static int mostRob3(int[] nums, int n, int ability) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (nums[i] <= ability) {
				ans++; 
				i++; //等效于i+2
			}
		}
		return ans;
	}
	// (max-min+1)范围二分，每次二分判断一遍数组足够与否：参考笔记截图

}
