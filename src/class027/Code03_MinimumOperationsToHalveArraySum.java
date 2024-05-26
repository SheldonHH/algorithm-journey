package class027;

import java.util.PriorityQueue;

// 将数组和减半的最少操作次数
// 测试链接 : https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/

// 每次可以把值/2
// 多少次操作能做到，整体累加和减半的目标，减少的幅度要达到sum/2的规格
// 贪心如此直白
// 如果数组中只能把一个数/2，当然选择最大的，砍掉一半，看什么时候整体累加和
// 题目说：任何一个数减少到恰好一半，所以.5也算
// 7 -> 3.5,所以用double类型
public class Code03_MinimumOperationsToHalveArraySum {

	// 提交时把halveArray1改名为halveArray
	public static int halveArray1(int[] nums) {
		// 大根堆，所有数加到大根堆里面

		// 大根堆，减半之后再放回去，看是多少，周而复始
		PriorityQueue<Double> heap = new PriorityQueue<>((a, b) -> b.compareTo(a));
		double sum = 0;
		for (int num : nums) {
			heap.add((double) num);
			sum += num;
		}
		// sum，整体累加和，-> 要减少的目标！
		sum /= 2;
		int ans = 0;
		for (double minus = 0, cur; minus < sum; ans++, minus += cur) {
			cur = heap.poll() / 2;
			heap.add(cur);
		}
		return ans;
	}

	public static int MAXN = 100001;

	public static long[] heap = new long[MAXN];

	public static int size; // 等于堆的长度

	// 提交时把halveArray2改名为halveArray
	// 让每一个数乘以2的20次方变成某一个long类型的数，新数组的也减少到1半效果是一样的
	// 整形int乘以2的20次方不会超过long类型64位，不会溢出
	// 原来是5，准备的20精度是自己控制
	public static int halveArray2(int[] nums) {
		size = nums.length;
		long sum = 0;
		//数字加入的过程中，乘之后，所有的数建立出一个大根堆出来
		for (int i = size - 1; i >= 0; i--) {
			heap[i] = (long) nums[i] << 20; 
			sum += heap[i]; //也是long类型
			heapify(i); 
		}
		sum /= 2;
		int ans = 0;
		for (long minus = 0; minus < sum; ans++) { 
			heap[0] /= 2;  // 每次从堆顶拿元素算幅度吗　
			minus += heap[0]; // 加好幅度之后
			heapify(0); //顶部heapify建好堆
		}
		return ans;
	}
	// 从底到顶建立大根堆，O(n)时间复杂度
	public static void heapify(int i) {
		int l = i * 2 + 1;
		while (l < size) {
			int best = l + 1 < size && heap[l + 1] > heap[l] ? l + 1 : l;
			best = heap[best] > heap[i] ? best : i;
			if (best == i) {
				break;
			}
			swap(best, i);
			i = best;
			l = i * 2 + 1;
		}
	}

	public static void swap(int i, int j) {
		long tmp = heap[i];
		heap[i] = heap[j];
		heap[j] = tmp;
	}

}
