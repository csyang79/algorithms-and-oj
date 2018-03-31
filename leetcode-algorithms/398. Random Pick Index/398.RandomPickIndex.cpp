//reservoir smapling, O(n) time with one pass and O(1) space 
class Solution {
public:
    Solution(vector<int> nums) : _nums(nums) {
        
    }
    
    int pick(int target) {
        int res = -1;
        int cnt = 0;
        for (int i = 0;  i < _nums.size(); ++i)
        {
            if (_nums[i] != target)
                continue;
            if (cnt++ == 0)
                res = i;
            else if (rand() % cnt == 0)
                res = i;
        }
        return res;
    }
private:
    vector<int> _nums;
};
