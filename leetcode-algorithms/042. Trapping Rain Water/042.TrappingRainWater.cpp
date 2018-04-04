//not optimal
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 2)
            return 0;
        int idx = 0;
        for (int i = 1; i < height.size(); ++i)
            if (height[i] > height[idx])
                idx = i;
        int res = 0, cur_max = 0;
        for (int i = 0; i < idx; ++i)
        {
            cur_max = height[i] > cur_max ? height[i] : cur_max;
            res += cur_max - height[i];
        }
        cur_max = 0;
        for (int i = height.size() - 1; i > idx; --i)
        {
            cur_max = height[i] > cur_max ? height[i] : cur_max;
            res += cur_max - height[i];
        }
        return res;
    }
};
//double pointer, one pass
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, level = 0, lower = 0, res = 0;
        while (left < right)		
        {
            lower = height[height[left] < height[right] ? left++ : right--];	//no need find max
            level = max(level, lower);
            res += level - lower;
        }
        return res;
    }
};
