class Solution {
public:
    int longestPalindrome(string s) {
        int freq[256] = {0};
        for (char c : s)
            ++freq[c];
        int res = 0;
        for (int i = 0; i < 256; ++i)
            res += freq[i] >> 1 << 1;
        return res < s.size() ? res + 1 : res;
    }
};
