class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        for (auto i : nums)
            if (i != 0)
                nums[idx++] = i;
        while (idx < n)
            nums[idx++] = 0;
    }
};
