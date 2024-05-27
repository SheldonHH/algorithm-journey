package class025;

// 堆结构和堆排序，填函数练习风格
// 测试链接 : https://leetcode.cn/problems/sort-an-array/
public class Code02_HeapSort {

	public static int[] sortArray(int[] nums) {
		if (nums.length > 1) {
			// heapSort1为从顶到底建堆然后排序
			// heapSort2为从底到顶建堆然后排序
			// 用哪个都可以
			// heapSort1(nums);
			heapSort2(nums);
		}
		return nums;
	}

	// i位置的数，向上调整大根堆
	// arr[i] = x，x是新来的！往上看，直到不比父亲大，或者来到0位置(顶)
	public static void heapInsert(int[] arr, int i) {
		while (arr[i] > arr[(i - 1) / 2]) {
			swap(arr, i, (i - 1) / 2);
			i = (i - 1) / 2;
		}
	}

	// 数组N个，完全二叉树高度 logN
	// 小于等于7个节点：高度3层
	// 小于等于15个节点：高度4层
	// 小于等于31个节点：高度5层
	// 小于等于63个节点：高度6层
	// i位置的数，变小了，又想维持大根堆结构
	// 向下调整大根堆
	// 当前堆的大小为size
	public static void heapify(int[] arr, int i, int size) {
		int l = i * 2 + 1;
		while (l < size) { // 发现左侧孩子的下标不越界，就有孩子，因为是完全二叉树
			// 有左孩子，l   右孩子，l+1
			// 评选，最强的孩子，是哪个下标的孩子
			// 既有右孩子，右孩子还比左孩子大
			// 没有右，左为最强下标
			// 有右，且比左大，右为最强下标
			// 有右，且没有比左大，左为最强下标
			int best = l + 1 < size && arr[l + 1] > arr[l] ? l + 1 : l;
			// 上面已经评选了最强的孩子，接下来，当前的数和最强的孩子之间，最强下标是谁
			best = arr[best] > arr[i] ? best : i;
			if (best == i) { // 居然最强的是你自己，说明不用再往下扎了，已经是大根堆了
				break;
			}
			// 最强不是自己，那么就和最强的孩子交换
			swap(arr, best, i);
			i = best; //你来到最强的孩子的位置
			l = i * 2 + 1; // 新的左孩子
		}
	}

	public static void swap(int[] arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

	// 从顶到底建立大根堆，O(n * logn)
	// 依次弹出堆内最大值并排好序，O(n * logn)
	// 整体时间复杂度O(n * logn)
	public static void heapSort1(int[] arr) {
		int n = arr.length;
		for (int i = 0; i < n; i++) {
			heapInsert(arr, i);
		}
		int size = n;
		while (size > 1) {
			swap(arr, 0, --size);
			heapify(arr, 0, size);
		}
	}

	// 从底到顶建立大根堆，O(n)
	// 依次弹出堆内最大值并排好序，O(n * logn)
	// 整体时间复杂度O(n * logn)
	public static void heapSort2(int[] arr) {
		int n = arr.length;
		for (int i = n - 1; i >= 0; i--) {
			heapify(arr, i, n);
		}
		int size = n;
		while (size > 1) {
			swap(arr, 0, --size);
			heapify(arr, 0, size);
		}
	}

}