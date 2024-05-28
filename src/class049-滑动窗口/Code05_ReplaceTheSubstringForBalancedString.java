package class049;

// 替换子串得到平衡字符串
// 有一个只含有 'Q', 'W', 'E', 'R' 四种字符，且长度为 n 的字符串。
// 假如在该字符串中，这四个字符都恰好出现 n/4 次，那么它就是一个「平衡字符串」。
// 给你一个这样的字符串 s，请通过「替换一个子串」的方式，使原字符串 s 变成一个「平衡字符串」。
// 你可以用和「待替换子串」长度相同的 任何 其他字符串来完成替换。
// 请返回待替换子串的最小可能长度。
// 如果原字符串自身就是一个平衡字符串，则返回 0。
// 测试链接 : https://leetcode.cn/problems/replace-the-substring-for-balanced-string/
public class Code05_ReplaceTheSubstringForBalancedString {
// 收入的字符一定是4的整数倍 https://imgur.com/drzl0Pf
// 范围单调性非常明显
// 若整个字符串是平衡的，那么每种字符的数量是n/4
// 划线的位置是可以自由编号的位置

	// Q W E R
	// 0 1 2 3
	// 先转换字符串，变成arr数组
	// "W Q Q R R E"
	// 1 0 0 3 3 2
	// cnts[1] = 1; 出现了1次1 Q
	// cnts[0] = 2; 出现了2次0 W	
	// cnts[2] = 1; 出现了1次2 E	
	// cnts[3] = 2;	出现了2次3 R
	public static int balancedString(String str) {
		int n = str.length();
		int[] arr = new int[n];
		int[] cnts = new int[4];
		for (int i = 0; i < n; i++) {
			char c = str.charAt(i);
			arr[i] = c == 'W' ? 1 : (c == 'E' ? 2 : (c == 'R' ? 3 : 0));
			cnts[arr[i]]++;
		}
		// str : 长度是4的整数倍，n
		// 每种字符出现的个数 : n/4
		int require = n / 4;
		int ans = n;  	// 至少要修改多长的子串，才能做到四种字符一样多
		// 自由变化的窗口l....r
		// l到r范围内自由变化，请问能否让整体字符变得一样多
		for (int l = 0, r = 0; l < n; l++) {
			// l = 0, r= 0, 窗口0长度，没有自由区域
			// l...r-1 : [l,r) 左闭右开
			//ok方法：判断l到r-1范围内的字符是否能变成一样多
			while (!ok(cnts, r - l, require) && r < n) {  //!零长度的不能做到，但窗口又可以扩的情况下（r<n还有努力的空间，什么时候r==n了）
				// cnts : 窗口之外的统计
				cnts[arr[r++]]--; // 词频--，让窗口右边界向右扩
			}
			// 1) l...r-1 [l,r) ，做到了！
			// 2) r == n，也没做到
			if (ok(cnts, r - l, require)) {
				ans = Math.min(ans, r - l);
			}
			// [l,r)，不被cnts统计到的
			//   l+1
			cnts[arr[l]]++;
		}
		return ans;
	}

// 既然有每一种字符必须达到的数量，那么四种字符在这个窗口之外的词频都必须小于等于20，任何一种大于20，肯定不行
// https://www.bilibili.com/opus/936578985418031143?spm_id_from=333.999.0.0

	// cnts : l...r范围上的字符不算！在自由变化的窗口之外，每一种字符的词频统计
	// len : 自由变化窗口的长度
	// require : 每一种字符都要达到的数量
	// 返回值 : 请问能不能做到
	public static boolean ok(int[] cnts, int len, int require) {
		for (int i = 0; i < 4; i++) {
			// 0 1 2 3
			if (cnts[i] > require) { // 任何一种的词频超过了要求，直接返回false
				return false;
			}
			// require - cnts[i] : 20 - 16 = 4 每一种字符需要补充多少个
			len -= require - cnts[i]; // 要补充多少个，我的len就consume多少个
		}
		return len == 0; // 补偿的长度刚好是自由支配的长度
	}

}
