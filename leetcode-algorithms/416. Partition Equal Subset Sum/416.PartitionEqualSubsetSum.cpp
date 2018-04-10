class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (sum & 1)
            return false;
        bitset<20001> dp;
        for (int i = 0, dp[0] = 1; i < nums.size(); ++i)
            for (int j = sum / 2; j >= nums[i]; --j)
                dp[j] = dp[j] || dp[j - nums[i]];
        return dp[sum / 2];
    }
};	
