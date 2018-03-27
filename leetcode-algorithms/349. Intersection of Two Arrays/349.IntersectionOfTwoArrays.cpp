class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset(nums1.begin(), nums1.end());
        vector<int> ans;
        for (int i : nums2)
            if (uset.erase(i))
                ans.push_back(i);
        return ans;
    }
};
