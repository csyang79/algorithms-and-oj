// O(m * n)
class Solution {
	public int strStr(String haystack, String needle) {
		if (needle.isEmpty())
			return 0;
		int lengthOfHaystack = haystack.length();
		int lengthOfNeedle = needle.length();
		for (int i = 0;  i <= lengthOfHaystack - lengthOfNeedle; ++i) {
			int j = 0;
			for (; j < lengthOfNeedle && haystack.charAt(i + j) == needle.charAt(j); ++j);
			if (j == lengthOfNeedle)
				return i;
		}
		return -1;
	}
}

/*
class Solution {
	public int strStr(String haystack, String needle) {
		if (needle == null || haystack == null)
			return -1;
		if (needle.isEmpty())
			return 0;
		final int lengthOfHaystack = haystack.length();
		final int lengthOfNeedle = needle.length();
		if (lengthOfNeedle > lengthOfHaystack)
			return -1;
		for (int i = 0; i <= lengthOfHaystack - lengthOfNeedle; ++i)
		{
			int j;
			for (j = 0; j < lengthOfNeedle; ++j) {
				if (needle.charAt(j) != haystack.charAt(i + j))
					break;
			}
			if (j == lengthOfNeedle)
				return i;
		}
		return -1;
	}
}
*/
