package class049;

import java.util.Arrays;

// 无重复字符的最长子串
// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。 substring
// 测试链接 : https://leetcode.cn/problems/longest-substring-without-repeating-characters/
public class Code02_LongestSubstringWithoutRepeatingCharacters {

// 以每个位置结尾情况下，最长的无重复字符的子串长度
	public static int lengthOfLongestSubstring(String str) {
		char[] s = str.toCharArray();
		int n = s.length;
		// char -> int -> 0 ~ 255
		// 每一种字符上次出现的位置
		int[] last = new int[256];
		// 所有字符都没有上次出现的位置
		Arrays.fill(last, -1); // 把任何一个数字，没出现过设置为-1，这样求max的过程中不会被干扰到
		// 不含有重复字符的 最长子串 的长度
		int ans = 0;
		// 这个位置向左再进来一个字符就崩了，所以左=max{左，X上一次出现的位+1}谁 : https://www.bilibili.com/opus/936582769307287586?spm_id_from=333.999.0.0
		for (int l = 0, r = 0; r < n; r++) {
			l = Math.max(l, last[s[r]] + 1); // (max实际上就是谁离的进加谁) 
			// 上一次的左边界和上一次出现的r的字符上次出现的位置
			ans = Math.max(ans, r - l + 1);
			// 更新当前字符上一次出现的位置
			last[s[r]] = r;
		}
		return ans;
	}

}

// 范围和单调性的关系，一旦不达标，你得缩减范围：https://www.bilibili.com/opus/936590633342074947?spm_id_from=333.999.0.0
// demo一个维持不变的情况
// d c e f z k y
// l           i 


// demo一个吐出的情况 
// d c e f z k e
// l           i 
	//   l  (来到上次出现加1)
