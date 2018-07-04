//greedy algorithm
class Solution {
	public:
		int maxArea(vector<int>& height) {
			int left = 0, right = height.size() - 1;
			int max_area = 0;
			int m, area;
			while (left < right)
			{
				m = height[left] < height[right] ? left++ : right--;
				area = (right - left + 1) * height[m];
				max_area = area > max_area ? area : max_area;
			}
			return max_area;
		}
};
