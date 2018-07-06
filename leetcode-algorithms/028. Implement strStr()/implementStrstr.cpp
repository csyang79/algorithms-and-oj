//O(n * m)
class Solution {
	public:
		int strStr(string haystack, string needle) {
			if (needle.empty())
				return 0;
			if (haystack.size() < needle.size())
				return -1;
			int sz = haystack.size() - needle.size();
			for (int i = 0, j; i <= sz; ++i)
			{
				for (j = 0; j < needle.size() && needle[j] == haystack[i]; ++j, ++i);
				i -= j;
				if (j == needle.size())
					return i;
			}
			return -1;
		}
};
