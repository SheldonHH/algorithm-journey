package class070;

// 环形数组的子数组最大累加和
// 给定一个数组nums，长度为n
// nums是一个环形数组，下标0和下标n-1是连在一起的
// 返回环形数组中，子数组最大累加和
// 测试链接 : https://leetcode.cn/problems/maximum-sum-circular-subarray/

// 不隔断：最大累加和的部分
// 隔断：整体的部分减去最小累加和的部分（扣掉中间连续的部分让累加和尽量的小）
// 有没有特例
public class Code03_MaximumSumCircularSubarray {

	public static int maxSubarraySumCircular(int[] nums) {
		// all整体累加和， maxsum，minsum普通数组最大累加和，最小累加和
		int n = nums.length, all = nums[0], maxsum = nums[0], minsum = nums[0];
		for (int i = 1, maxpre = nums[0], minpre = nums[0]; i < n; i++) {
			all += nums[i]; // 来一个加
			maxpre = Math.max(nums[i], nums[i] + maxpre); // 子数组必须以i结尾的情况下，往左能延伸出来累加和最大
			maxsum = Math.max(maxsum, maxpre);

			minpre = Math.min(nums[i], nums[i] + minpre);
			minsum = Math.min(minsum, minpre);
		}
		// 1) maxsum
		// 2) all - minsum
		return all == minsum ? maxsum : Math.max(maxsum, all - minsum);// 两者可能性pk最大的
		// all == minsum：因为本体不允许有空数组的情况出现，所以答案应该是-1，而非0，参见
		// https://leetcode.com/problems/maximum-sum-circular-subarray/solutions/5225339/continuous-parts-are-interrupted-vs-not-interrupted-vs/
	}

}
