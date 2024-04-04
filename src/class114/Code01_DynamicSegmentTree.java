package class114;

// 动态开点线段树
// 一共有n个位置，编号从1~n，一开始所有位置的值为0
// 实现如下两个操作，一共会调用m次
// 操作1 : 将l~r范围的每个数增加v
// 操作2 : 返回l~r范围的累加和
// 1 <= n <= 10^9
// 1 <= m <= 10^3
// 测试链接 : https://www.luogu.com.cn/problem/P2781
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;

public class Code01_DynamicSegmentTree {

	// 范围1 ~ 10^9，线段树高度差不多30
	// 查询次数1000，每次查询都有左右两条边线
	// 每来到一个线段树的区间，都要分配左孩子、右孩子存储空间
	// 所以空间占用差不多1000 * 30 * 2 * 2 = 120000
	// 不过这只是最极端的估计，过程中又很多线段树区间被复用
	// 本题将空间设置在10^5规模就够用了(实验的结果)
	public static int LIMIT = 100001;

	public static int cnt;

	public static int[] left = new int[LIMIT];

	public static int[] right = new int[LIMIT];

	public static long[] sum = new long[LIMIT];

	public static long[] add = new long[LIMIT];

	public static void up(int hi, int li, int ri) {
		sum[hi] = sum[li] + sum[ri];
	}

	public static void down(int i, int ln, int rn) {
		if (add[i] != 0) {
			lazy(left[i], add[i], ln);
			lazy(right[i], add[i], rn);
			add[i] = 0;
		}
	}

	public static void lazy(int i, long v, int n) {
		sum[i] += v * n;
		add[i] += v;
	}

	public static void add(int jobl, int jobr, long jobv, int l, int r, int i) {
		if (jobl <= l && r <= jobr) {
			lazy(i, jobv, r - l + 1);
		} else {
			if (left[i] == 0) {
				left[i] = ++cnt;
			}
			if (right[i] == 0) {
				right[i] = ++cnt;
			}
			int mid = (l + r) >> 1;
			down(i, mid - l + 1, r - mid);
			if (jobl <= mid) {
				add(jobl, jobr, jobv, l, mid, left[i]);
			}
			if (jobr > mid) {
				add(jobl, jobr, jobv, mid + 1, r, right[i]);
			}
			up(i, left[i], right[i]);
		}
	}

	public static long query(int jobl, int jobr, int l, int r, int i) {
		if (jobl <= l && r <= jobr) {
			return sum[i];
		}
		if (left[i] == 0) {
			left[i] = ++cnt;
		}
		if (right[i] == 0) {
			right[i] = ++cnt;
		}
		int mid = (l + r) >> 1;
		down(i, mid - l + 1, r - mid);
		long ans = 0;
		if (jobl <= mid) {
			ans += query(jobl, jobr, l, mid, left[i]);
		}
		if (jobr > mid) {
			ans += query(jobl, jobr, mid + 1, r, right[i]);
		}
		return ans;
	}

	// 如果一次会执行多组测试数组
	// 那么每组测试完成后要clear空间
	public static void clear() {
		Arrays.fill(left, 1, cnt + 1, 0);
		Arrays.fill(right, 1, cnt + 1, 0);
		Arrays.fill(sum, 1, cnt + 1, 0);
		Arrays.fill(add, 1, cnt + 1, 0);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer in = new StreamTokenizer(br);
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		in.nextToken();
		int n = (int) in.nval;
		in.nextToken();
		int m = (int) in.nval;
		cnt = 1;
		long jobv;
		for (int i = 1, op, jobl, jobr; i <= m; i++) {
			in.nextToken();
			op = (int) in.nval;
			if (op == 1) {
				in.nextToken();
				jobl = (int) in.nval;
				in.nextToken();
				jobr = (int) in.nval;
				in.nextToken();
				jobv = (long) in.nval;
				add(jobl, jobr, jobv, 1, n, 1);
			} else {
				in.nextToken();
				jobl = (int) in.nval;
				in.nextToken();
				jobr = (int) in.nval;
				out.println(query(jobl, jobr, 1, n, 1));
			}
		}
		// 本题每组测试数据都单独运行
		// 可以不写clear方法
		// 但是如果多组测试数据串行调用
		// 就需要加上清空逻辑
		clear();
		out.flush();
		out.close();
		br.close();
	}

}
