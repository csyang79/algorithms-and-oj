class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        int n = citations.size(), cites = 0;
        vector<int> help(n + 1, 0);
        for (int i = 0; i < citations.size(); ++i)
        {
            if (citations[i] > n)
                ++help[n];
            else
                ++help[citations[i]];
        }
        for (int i = n; ; --i)
        {
            cites += help[i];
            if (cites >= i)
                return i;
        }
    }
};
