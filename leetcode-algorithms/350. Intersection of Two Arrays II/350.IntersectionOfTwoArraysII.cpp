class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> unmap;
        for (int i : nums1)
            ++unmap[i];
        vector<int> ans;
        for (int i : nums2)
            if (unmap[i] > 0)
            {
                --unmap[i];
                ans.push_back(i);
            }
        return ans;
    }
};
