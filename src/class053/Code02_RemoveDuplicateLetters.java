package class053;

import java.util.Arrays;

// 去除重复字母
// 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次
// 需保证 返回结果的字典序最小
// 要求不能打乱其他字符的相对位置
// 测试链接 : https://leetcode.cn/problems/remove-duplicate-letters/
public class Code02_RemoveDuplicateLetters {

	public static int MAXN = 26;

	public static int[] cnts = new int[MAXN];

	public static boolean[] enter = new boolean[MAXN];

	public static char[] stack = new char[MAXN];

	public static int r;

	public static String removeDuplicateLetters(String str) {
		Arrays.fill(cnts, 0);
		Arrays.fill(enter, false);
		r = 0;
		char[] s = str.toCharArray();
		for (char cha : s) {
			cnts[cha - 'a']++;
		}
		for (char cur : s) {
			if (!enter[cur - 'a']) {
				while (r > 0 && stack[r - 1] > cur && cnts[stack[r - 1] - 'a'] > 0) {
					enter[stack[r - 1] - 'a'] = false;
					r--;
				}
				stack[r++] = cur;
				enter[cur - 'a'] = true;
			}
			cnts[cur - 'a']--;
		}
		return String.valueOf(stack, 0, r);
	}

}
