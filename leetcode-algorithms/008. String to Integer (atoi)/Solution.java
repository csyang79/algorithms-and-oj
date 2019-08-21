class Solution {
	public int myAtoi(String str) {
		if (str == null || str.isEmpty())
			return 0;
		int cur = 0;
		while (cur < str.length() && str.charAt(cur) == ' ') {
			++cur;
		}
		int sign = 1;
		if (cur < str.length()) {
			if (str.charAt(cur) == '-')
				sign = -1;
			if (str.charAt(cur) == '+' || str.charAt(cur) == '-')
				++cur;
		}
		if (cur < str.length() && !Character.isDigit(str.charAt(cur))) {
			return 0;
		}
		int result = 0;
		while (cur < str.length() && Character.isDigit(str.charAt(cur))) {
			int digit = str.charAt(cur) - '0';
			if (result > Integer.MAX_VALUE / 10 || result == Integer.MAX_VALUE / 10 && digit > 7) {
				return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
			}
			result = result * 10 + digit;
			++cur;
		}
		return sign * result;
	}
}
