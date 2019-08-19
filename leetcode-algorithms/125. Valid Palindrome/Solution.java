/*class Solution {
    public boolean isPalindrome(String s) {
        String actual = s.replaceAll("[^A-Za-z0-9]", "").toLowerCase();
        String reverse = new StringBuilder(actual).reverse().toString();
        return actual.equals(reverse);
    }
}*/



class Solution {
	public boolean isPalindrome(String s) {
		if (s.length() < 2)
			return true;
		int left = 0;
		int right = s.length() - 1;
		while (true) {
			while (left < right && !Character.isLetterOrDigit(s.charAt(left))) {
				++left;
			}
			while (left < right && !Character.isLetterOrDigit(s.charAt(right))) {
				--right;
			}
			if (!(left < right)) {
				break;
			}
			if (Character.toLowerCase(s.charAt(left)) != Character.toLowerCase(s.charAt(right))){
				return false;
			} else {
				++left;
				--right;
			}
		}
		return true;
	}
}
