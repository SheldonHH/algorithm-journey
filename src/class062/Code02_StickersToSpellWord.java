package class062;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;

// 贴纸拼词
// 我们有 n 种不同的贴纸。每个贴纸上都有一个小写的英文单词。
// 您想要拼写出给定的字符串 target ，方法是从收集的贴纸中切割单个字母并重新排列它们
// 如果你愿意，你可以多次使用每个贴纸，每个贴纸的数量是无限的。
// 返回你需要拼出 target 的最小贴纸数量。如果任务不可能，则返回 -1
// 注意：在所有的测试用例中，所有的单词都是从 1000 个最常见的美国英语单词中随机选择的
// 并且 target 被选择为两个随机单词的连接。
// 测试链接 : https://leetcode.cn/problems/stickers-to-spell-word/

// 一个类型用多少张随便
// ✴ 给你长字符串，和一堆贴纸，每一个贴纸都可以剪开，零碎的贴到长字符串上
// 问你：最少需要多少张贴纸，才能把长字符串贴完
// 搞定之后，看到剩余什么，再进行下一层，知道空字符串（✴展开的层数就贴纸的张数✴）
public class Code02_StickersToSpellWord {

	public static int MAXN = 401;

	public static String[] queue = new String[MAXN];

	public static int l, r; // l -> poll, r -> offer

	// 下标0 -> a
	// 下标1 -> b
	// 下标2 -> c
	// ...
	// 下标25 -> z
	public static ArrayList<ArrayList<String>> graph = new ArrayList<>();

	static {
		for (int i = 0; i < 26; i++) {
			graph.add(new ArrayList<>()); // 26个桶，剩余什么就在对应的桶里面寻找：https://www.bilibili.com/opus/936523223857627156?spm_id_from=333.999.0.0
		}
	}

	public static HashSet<String> visited = new HashSet<>();

	// 宽度优先遍历的解法，最好理解，难点在于想到
	
	// 也可以使用动态规划
	// 后续课程会有动态规划专题讲解
	// 剪枝策略：先满足前缀
	public static int minStickers(String[] stickers, String target) { // 几张贴纸能搞定target
		for (int i = 0; i < 26; i++) {
			graph.get(i).clear();
		}
		visited.clear(); // 用过的贴纸
		for (String str : stickers) {
			str = sort(str);
			// 把每一个贴纸排序后的贴纸，建图
			for (int i = 0; i < str.length(); i++) {
				if (i == 0 || str.charAt(i) != str.charAt(i - 1)) {
					graph.get(str.charAt(i) - 'a').add(str); // 首字符不重复的贴纸
				}
			}
		}
		target = sort(target);
		// 建图过程：
		visited.add(target);
		l = r = 0;
		queue[r++] = target;
		int level = 1;
		// 使用队列的形式是整层弹出！！！
		while (l < r) {
			int size = r - l; // 当前层的size
			for (int i = 0; i < size; i++) {
				String cur = queue[l++]; // 弹出字符串
				for (String s : graph.get(cur.charAt(0) - 'a')) { // 就看我首字符是什么的贴纸：https://www.bilibili.com/opus/936525976932712489?spm_id_from=333.999.0.0
					String next = next(cur, s); // 告诉你剩余的字符串是啥，当前的贴纸是啥，给我剩余的结果
					if (next.equals("")) { // 消掉的目标达成
						return level;
					} else if (!visited.contains(next)) {  //剩余部分没进入过队列
						visited.add(next);  // 标记进入过队列
						queue[r++] = next; // 进入队列，r++
					}
				}
			}
			level++;
		}
		return -1; // 宽度有限遍历结束还没有遇到结果，返回-1没有办法把target贴完
	}
	// 排序与否不影响结果
	public static String sort(String str) {
		char[] s = str.toCharArray();
		Arrays.sort(s); //每一个贴纸都排序
		return String.valueOf(s); // 排序后的贴纸
	}

// builder.append(t.charAt(i++)); // 留下因为目标的字符小，所以留下，因为后面用得到到
// 因为需要得出剩余的字符串，https://www.bilibili.com/opus/936527523138764801?spm_id_from=333.999.0.0
	public static String next(String t, String s) { //类似merge的过程，t是目标，s是当前的贴纸
		StringBuilder builder = new StringBuilder();
		for (int i = 0, j = 0; i < t.length();) {
			if (j == s.length()) { // 贴纸用完了
				builder.append(t.charAt(i++));
			} else {
				if (t.charAt(i) < s.charAt(j)) { // 目标的字符小于当前贴纸的字符
					builder.append(t.charAt(i++)); // 留下因为目标的字符小，所以留下，因为后面用得到到
				} else if (t.charAt(i) > s.charAt(j)) {
					j++;
				} else { // t[i] == s[j]相等，继续
					i++;
					j++;
				}
			}
		}
		return builder.toString();
	}

}
