//格雷码，增量构造
class Solution {
	public:
		vector<int> grayCode(int n) {
			vector<int> gray{0};
			for (int i = 1; i <= n; ++i)
				for (int j = gray.size() - 1; j >= 0; --j)
					gray.push_back((1 << (i - 1)) + gray[j]);
			return gray;
		}
};
