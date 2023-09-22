package class061;

// Prim算法模版（洛谷）
// 静态空间实现
// 测试链接 : https://www.luogu.com.cn/problem/P3366
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;

// 以下的实现，即便是比赛也能通过
// 建图用链式前向星、堆也是用数组结构手写的，不用任何动态结构
// 这个实现留给有需要的同学
// 但是一般情况下并不需要做到这个程度
public class Code02_PrimStatic {

	public static int MAXN = 5001;

	public static int MAXM = 400001;

	public static int n, m;

	// 链式前向星建图
	public static int[] head = new int[MAXN];

	public static int[] next = new int[MAXM];

	public static int[] to = new int[MAXM];

	public static int[] weight = new int[MAXM];

	public static int cnt;

	// 因为边的权重数据都在weight数组中
	// 所以需要比较边的权重，只需要有边的编号
	// 就可以从weight数组中拿出数据比较了
	// 所以小根堆只需要存储边的编号
	public static int[] heap = new int[MAXM];

	public static int heapSize;

	// 节点有没有进入集合
	public static boolean[] set = new boolean[MAXN];

	// 一共有多少个点进入了集合
	public static int nodeCnt;

	public static void build() {
		cnt = 1;
		heapSize = 0;
		nodeCnt = 0;
		Arrays.fill(head, 1, n + 1, 0);
		Arrays.fill(set, 1, n + 1, false);
	}

	public static void addEdge(int u, int v, int w) {
		next[cnt] = head[u];
		to[cnt] = v;
		weight[cnt] = w;
		head[u] = cnt++;
	}

	// 编号为e的边进入小根堆，根据边的权重来组织小根堆
	public static void push(int e) {
		int i = heapSize++;
		heap[i] = e;
		while (weight[heap[i]] < weight[heap[(i - 1) / 2]]) {
			swap(i, (i - 1) / 2);
			i = (i - 1) / 2;
		}
	}

	// 小根堆中弹出权重最小的边的编号
	public static int pop() {
		int e = heap[0];
		heap[0] = heap[--heapSize];
		int i = 0;
		int l = 1;
		while (l < heapSize) {
			int best = l + 1 < heapSize && weight[heap[l + 1]] < weight[heap[l]] ? l + 1 : l;
			best = weight[heap[best]] < weight[heap[i]] ? best : i;
			if (best == i) {
				break;
			}
			swap(best, i);
			i = best;
			l = i * 2 + 1;
		}
		return e;
	}

	public static boolean isEmpty() {
		return heapSize == 0;
	}

	public static void swap(int i, int j) {
		int tmp = heap[i];
		heap[i] = heap[j];
		heap[j] = tmp;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer in = new StreamTokenizer(br);
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		while (in.nextToken() != StreamTokenizer.TT_EOF) {
			n = (int) in.nval;
			in.nextToken();
			m = (int) in.nval;
			build();
			for (int i = 0, u, v, w; i < m; i++) {
				in.nextToken(); u = (int) in.nval;
				in.nextToken(); v = (int) in.nval;
				in.nextToken(); w = (int) in.nval;
				addEdge(u, v, w);
				addEdge(v, u, w);
			}
			int ans = prim();
			out.println(nodeCnt == n ? ans : "orz");
		}
		out.flush();
		out.close();
		br.close();
	}

	public static int prim() {
		set[1] = true;
		nodeCnt = 1;
		for (int ei = head[1]; ei > 0; ei = next[ei]) {
			push(ei);
		}
		int ans = 0;
		while (!isEmpty()) {
			int edge = pop();
			int u = to[edge];
			int w = weight[edge];
			if (!set[u]) {
				set[u] = true;
				nodeCnt++;
				ans += w;
				for (int ei = head[u]; ei > 0; ei = next[ei]) {
					push(ei);
				}
			}
		}
		return ans;
	}

}