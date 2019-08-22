class Solution {
	public boolean isMatch(String s, String p) {
		return isMatch(s, 0, s.length(), p, 0, p.length());
	}
	private boolean isMatch(String s, int cur1, int m, String p, int cur2, int n) {
		if (cur2 == n)
			return cur1 == m;
		if (cur2 + 1 == n || p.charAt(cur2 + 1) != '*') {
			if (cur1 != m && (s.charAt(cur1) == p.charAt(cur2) || p.charAt(cur2) == '.')) {
				return isMatch(s, cur1 + 1, m, p, cur2 + 1, n);
			} else {
				return false;
			}
		} else {
			if (isMatch(s, cur1, m, p, cur2 + 2, n))
				return true;
			while (cur1 != m && (s.charAt(cur1) == p.charAt(cur2) || p.charAt(cur2) == '.')) {
				if (isMatch(s, ++cur1, m, p, cur2 + 2, n))
					return true;
			}
			return false;
		}
	}
}
