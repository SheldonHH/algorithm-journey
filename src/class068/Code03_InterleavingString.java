package class068;

// 交错字符串
// 给定三个字符串 s1、s2、s3
// 请帮忙验证s3是否由s1和s2交错组成
// 测试链接 : https://leetcode.cn/problems/interleaving-string/
public class Code03_InterleavingString {

	// 已经展示太多次从递归到动态规划了
	// 直接写动态规划吧
	// s1的前i个字符和s2的前j个字符，能否交错组成s3的前i+j个字符
	// 二维表表示三个字符串的前缀关系
	public static boolean isInterleave1(String str1, String str2, String str3) {
		if (str1.length() + str2.length() != str3.length()) {
			return false;
		}
		char[] s1 = str1.toCharArray();
		char[] s2 = str2.toCharArray();
		char[] s3 = str3.toCharArray(); 
		int n = s1.length;
		int m = s2.length;
		// dp[i][j]:
		// s1[前缀长度为i]和s2[前缀长度为j]，能否交错组成出s3[前缀长度为i+j]
		boolean[][] dp = new boolean[n + 1][m + 1];
		dp[0][0] = true; // s1的前缀长度为0，s2的前缀长度为0，能否交错组成s3的前缀长度为0，当然能搞定
		for (int i = 1; i <= n; i++) { //s1单枪匹马和s3比较
			// 有任何一步不等，后面的都不用看了，因为不可能交错组成s3
			if (s1[i - 1] != s3[i - 1]) { 
				break;
			}
			dp[i][0] = true; //第0列，s2的前缀长度为0
		}
		// 同理
		for (int j = 1; j <= m; j++) {
			if (s2[j - 1] != s3[j - 1]) {
				break;
			}
			dp[0][j] = true;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
						
				// s3的最后一个字符来自谁？s1的最后一个字符还是s2的最后一个字符
				// 若s1的最后一个字符和s3的最后一个字符相等，那马查看s1的前i-1个字符和s2的前j个字符能否交错组成s3的前i+j-1个字符
				// s1[i-1] s2[j] => s3[i+j-1] dp[i-1][j]
				// 若s2的最后一个字符和s3的最后一个字符相等，那马查看s1的前i个字符和s2的前j-1个字符能否交错组成s3的前i+j-1个字符
				// s1[i] s2[j-1] => s3[i+j-1] dp[i][j-1]
				// 最小路径和问题，依赖左上角和上方的位置
				dp[i][j] = (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) || (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);
			}
		}
		return dp[n][m];
	}

	// 空间压缩
	public static boolean isInterleave2(String str1, String str2, String str3) {
		if (str1.length() + str2.length() != str3.length()) {
			return false;
		}
		char[] s1 = str1.toCharArray();
		char[] s2 = str2.toCharArray();
		char[] s3 = str3.toCharArray();
		int n = s1.length;
		int m = s2.length;
		boolean[] dp = new boolean[m + 1];
		dp[0] = true;
		for (int j = 1; j <= m; j++) {
			if (s2[j - 1] != s3[j - 1]) {
				break;
			}
			dp[j] = true;
		}
		for (int i = 1; i <= n; i++) {
			dp[0] = s1[i - 1] == s3[i - 1] && dp[0];
			for (int j = 1; j <= m; j++) {
				dp[j] = (s1[i - 1] == s3[i + j - 1] && dp[j]) || (s2[j - 1] == s3[i + j - 1] && dp[j - 1]);
			}
		}
		return dp[m];
	}

}
