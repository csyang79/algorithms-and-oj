//O(n)
class Solution {
	public:
		void nextPermutation(vector<int>& nums) {
			if (nums.size() < 2)
				return;
			int k = -1, j;
			for (int i = nums.size() - 2; i >= 0; --i)
				if (nums[i] < nums[i + 1])
				{
					k = i;
					break;
				}
			if (k == -1)
			{
				Reverse(nums.begin(), nums.end());
				return;
			}
			for (int i = nums.size() - 1; ; --i)
			{
				if (nums[i] > nums[k])
				{
					j = i;
					break;
				}
			}
			Swap(nums[k], nums[j]);
			Reverse(nums.begin() + k + 1, nums.end());
			return;
		}
	private:
		template <typename It>
			void Reverse(It begin, It end)
			{
				if (end - begin < 2)
					return;
				--end;
				while (begin < end)
					Swap(*begin++, *end--);
			}
		void Swap(int &a, int &b)
		{
			int t = a;
			a = b;
			b = t;
		}
};
