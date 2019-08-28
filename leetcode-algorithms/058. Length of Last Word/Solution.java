// 注意右边开始为0的情况
class Solution {
	public int lengthOfLastWord(String s) {
		int count = 0;
		int i = s.length() - 1;
		while (i >= 0 && s.charAt(i) == ' ')
			--i;
		while (i >= 0 && s.charAt(i) != ' ') {
			++count;
			--i;
		}
		return count;
	}
}
