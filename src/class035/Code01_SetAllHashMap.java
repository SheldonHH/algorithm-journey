package class035;

// setAll功能的哈希表
// 测试链接 : https://www.nowcoder.com/practice/7c4559f138e74ceb9ba57d76fd169967
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.HashMap;
// 要求setall, put, get全部是O(1)
// 加盖时间戳技巧 https://www.bilibili.com/opus/935769942432677888?spm_id_from=333.999.0.0
// 别修改里面的值，而是
public class Code01_SetAllHashMap {

	public static HashMap<Integer, int[]> map = new HashMap<>();
	public static int setAllValue; // 0
	public static int setAllTime;  // -1
	public static int cnt; //每进入一个值就++

	public static void put(int k, int v) {
		if (map.containsKey(k)) {
			int[] value = map.get(k);
			value[0] = v;
			value[1] = cnt++;
		} else {
			map.put(k, new int[] { v, cnt++ });
		}
	}

	public static void setAll(int v) {
		setAllValue = v;
		setAllTime = cnt++;
	}

	// 19d
	public static int get(int k) {// 比对时间
		if (!map.containsKey(k)) {
			return -1;
		}
		int[] value = map.get(k);
		// setAll时间比他更新 https://www.bilibili.com/opus/935770956063834136?spm_id_from=333.999.0.0
		// 看是拿setAllValue的值，还是自身的值，用时间戳技术
		if (value[1] > setAllTime) {
			return value[0];
		} else {
			return setAllValue;
		}
	}

	public static int n, op, a, b;

	//在 Java 中，main 函数必须放在一个类的内部，这是因为 Java 是一种纯面向对象的语言，
	// 在 C++ 中，main 函数是在类之外定义的。C++ 支持面向对象编程，但它不是纯面向对象的语言，因此允许在全局作用域中定义函数。
	// 是的，在 C++ 中，main 函数不应该放在类的内部。main 函数是程序的入口点，它是在全局作用域中定义的，而不是类的成员。
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer in = new StreamTokenizer(br);
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		while (in.nextToken() != StreamTokenizer.TT_EOF) {
			map.clear(); // 清空
			setAllValue = 0;
			setAllTime = -1;
			cnt = 0;
			n = (int) in.nval;
			for (int i = 0; i < n; i++) {
				in.nextToken();
				op = (int) in.nval;
				if (op == 1) {
					in.nextToken();
					a = (int) in.nval;
					in.nextToken();
					b = (int) in.nval;
					put(a, b);
				} else if (op == 2) {
					in.nextToken();
					a = (int) in.nval;
					out.println(get(a));
				} else {
					in.nextToken();
					a = (int) in.nval;
					setAll(a);
				}
			}
		}
		out.flush();
		out.close();
		br.close();
	}

}
