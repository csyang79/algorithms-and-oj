//double pointer
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int dict[256];
        fill_n(dict,256, -1);
        int len = 0;
        int l = -1;
        for (int i = 0; i < s.size(); ++i)
        {
            if (dict[s[i]] != -1)
                l = max(l, dict[s[i]]);
            len = max(len, i - l);
            dict[s[i]] = i;
        }
        return len;
    }
};
