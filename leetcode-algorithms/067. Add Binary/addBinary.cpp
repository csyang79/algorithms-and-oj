//string::npos
class Solution {
	public:
		string addBinary(string a, string b) {
			const int m = a.size();
			const int n = b.size();
			int carry = 0;
			string res(max(m, n) + 1, '0');
			for (int i = m - 1, j = n - 1, k = res.size(); i >= 0 || j >= 0 || carry; --i, --j)
			{
				int t1 = i >= 0 ? a[i] - '0' : 0;
				int t2 = j >= 0 ? b[j] - '0' : 0;
				int sum = t1 + t2 + carry;
				res[--k] = sum % 2 + '0';
				carry = sum / 2;
			}
			int idx = res.find_first_not_of('0');
			return idx == string::npos ? "0" : res.substr(idx);
		}
};
