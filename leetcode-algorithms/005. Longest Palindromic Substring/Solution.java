class Solution {
	public String longestPalindrome(String s) {
		if (s == null)
			return null;
		int n = s.length();
		if (n == 0)
			return "";
		int maxLen = 1;
		int start = 0;
		boolean[][] dp = new boolean[n][n];
		for (int i = 0; i < n; ++i) {
			dp[i][i] = true;
			for (int j = 0; j < i; ++j) {
				dp[j][i] = (s.charAt(i) == s.charAt(j)) && (i == j + 1 || dp[j + 1][i - 1]);
				if (dp[j][i] && i - j + 1> maxLen) {
					maxLen = i - j + 1;
					start = j;
				}
			}
		}
		return s.substring(start, start + maxLen);
	}
}
