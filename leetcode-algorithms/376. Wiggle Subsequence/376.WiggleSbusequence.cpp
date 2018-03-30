class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        
	int j = 1, start = 1;        
	while (j < nums.size() && nums[0] == nums[j])
            ++j;
        if (j == nums.size())
            return 1;
        nums[start] = nums[j];
        int flag = nums[0] < nums[1] ? 1 : -1;

        for (int i = j + 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[start])
            {
                if (flag == -1)
                {
                    nums[++start] = nums[i];
                    flag = 1;
                }
                else
                    nums[start] = nums[i];
            }
            else if (nums[i] < nums[start])
            {
                if (flag == 1)
                {
                    nums[++start] = nums[i];
                    flag = -1;
                }
                else
                    nums[start] = nums[i];
            }
        }
        return start + 1;
    }
};
