class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        const int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        int maxlen = 1, start = 0;
        for (int i = 0; i < len; ++i)
        {
            dp[i][i] = true;
            for (int j = 0; j < i; ++j)
            {
                dp[j][i] = (s[i] == s[j]) && (i == j + 1 || dp[j + 1][i - 1]);
                if (dp[j][i] && i - j + 1 > maxlen)
                {
                    maxlen = i - j + 1;
                    start = j;
                }
            }   
        }
        return s.substr(start, maxlen);
    }
};
