package class038;

import java.util.HashSet;

// 字符串的全部子序列
// 子序列本身是可以有重复的，只是这个题目要求去重
// 测试链接 : https://www.nowcoder.com/practice/92e6247998294f2c933906fdedbc6e6a
public class Code01_Subsequences {

	public static String[] generatePermutation1(String str) {
		char[] s = str.toCharArray();
		HashSet<String> set = new HashSet<>(); //收集结果去重
		// https://www.bilibili.com/opus/935818042000015366?spm_id_from=333.999.0.0
		f1(s, 0, new StringBuilder(), set);
		int m = set.size();
		String[] ans = new String[m];
		int i = 0;
		for (String cur : set) {
			ans[i++] = cur;
		}
		return ans;
	}

	// s[i...]，之前决定的路径path，set收集结果时去重
	public static void f1(char[] s, int i, StringBuilder path, HashSet<String> set) {
		if (i == s.length) {
			set.add(path.toString());
		} else {
			path.append(s[i]); // 加到路径中去
			f1(s, i + 1, path, set);
			path.deleteCharAt(path.length() - 1); // 从路径中移除
			f1(s, i + 1, path, set);
		}
	}



	public static String[] generatePermutation2(String str) {
		char[] s = str.toCharArray();
		HashSet<String> set = new HashSet<>();
		f2(s, 0, new char[s.length], 0, set);
		int m = set.size();
		String[] ans = new String[m];
		int i = 0;
		for (String cur : set) {
			ans[i++] = cur;
		}
		return ans;
	}
	// size表示路径填入了几个字符了
	// 利用了数组不断复用的原理
	// 为啥这样写之后不用擦出
	// path和size依然是全局的
	// size:路径填入了几个

	// 有效的其实就是a,b 两个用专属的size来管谁有效，谁没效
	public static void f2(char[] s, int i, char[] path, int size, HashSet<String> set) {
		if (i == s.length) {
			set.add(String.valueOf(path, 0, size));
		} else {
			path[size] = s[i];
			f2(s, i + 1, path, size + 1, set);
			// 有效的其实就是a,b 两个用专属的size来管谁有效，谁没效
			f2(s, i + 1, path, size, set);
		}
	}

}
