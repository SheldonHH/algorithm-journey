package class049;

// 累加和大于等于target的最短子数组长度
// 给定一个含有 n 个正整数的数组和一个正整数 target
// 找到累加和 >= target 的长度最小的子数组并返回其长度
// 如果不存在符合条件的子数组返回0
// 测试链接 : https://leetcode.cn/problems/minimum-size-subarray-sum/
public class Code01_MinimumSizeSubarraySum {
// https://imgur.com/ks9LOrd
	public static int minSubArrayLen(int target, int[] nums) {
		int ans = Integer.MAX_VALUE;
		// 必须以r位置结尾求出答案
		for (int l = 0, r = 0, sum = 0; r < nums.length; r++) {
			sum += nums[r];
			// 范围和指标之间的关系
			// 核心在于范围和累加和之间是具有单调性关系的，范围变大累加和也变大
			while (sum - nums[l] >= target) {
				// sum : nums[l....r]
				// 如果l位置的数从窗口出去，还能继续达标，那就出去
				sum -= nums[l++]; // l位置的数再累加和能减下来，且达标
			}
			if (sum >= target) { 
				ans = Math.min(ans, r - l + 1); // 找到更小的答案
			}
		}
		// 从来没发现过答案，有答案返回ans就可以
		return ans == Integer.MAX_VALUE ? 0 : ans;
	}

}
