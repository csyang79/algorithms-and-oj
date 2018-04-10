//O(n)???
//note a ^ b = c, then a ^ c = b, b ^ c = a
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0, mask = 0;
        for (int i = 31; i >= 0; --i)
        {
            mask |= 1 << i;
            set<int> Set;
            for (int num : nums)		
                Set.insert(num & mask);			//why O(n)?
            int tmp = max | (1 << i);
            for (int prefix : Set)
                if (Set.find(prefix ^ tmp) != Set.end())		//judge tmp exists or not
                {
                    max = tmp;
                    break;
                }
        }
        return max;
    }
};
