//将9变成0，注意边界
class Solution {
	public:
		vector<int> plusOne(vector<int>& digits) {
			int i;
			for (i = digits.size() - 1; i >= 0 && digits[i] == 9; --i)
				digits[i] = 0;
			if (i == -1)
				digits.insert(digits.begin(), 1);
			else
				digits[i] += 1;
			return digits;
		}
};
