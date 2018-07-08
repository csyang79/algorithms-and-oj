class Solution {
	public:
		void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
			for (int k = m + n - 1; n > 0; --k)
			{
				if (m <= 0 || nums1[m - 1] < nums2[n - 1])
					nums1[k] = nums2[--n];
				else
					nums1[k] = nums1[--m];
			}
		}
};
