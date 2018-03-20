class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1, curmax = nums[0], curmin = nums[0]; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
                std::swap(curmax, curmin);
            curmax = std::max(nums[i], nums[i] * curmax);
            curmin = std::min(nums[i], nums[i] * curmin);
            ans = std::max(ans, curmax);
        }
        return ans;
    }
};