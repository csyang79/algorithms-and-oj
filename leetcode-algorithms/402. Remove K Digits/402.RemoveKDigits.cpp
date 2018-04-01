class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size())
            return "0";
        string res;
        for (char c : num)
        {
            while (k && !res.empty() && res.back() > c)
            {
                --k;
                res.pop_back();
            }
            res.push_back(c);
        }
        int t;
        if (k != 0)
            res = res.substr(0, res.size() - k);
        if ((t = res.find_first_not_of('0')) != string::npos)
            return res.substr(t);
        return "0";
    }
};
