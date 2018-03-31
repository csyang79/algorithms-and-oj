class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for (char c : s)
        {
            while (idx < t.size() && t[idx] != c)
                ++idx;
            if (t[idx] != c)
                return false;
            ++idx;
        }
        return true;
    }
};

//god like
class Solution {
public:
    bool isSubsequence(string s, string t) {
        const char *p = s.c_str(), *q = t.c_str();
        while (*q)
            p += *p == *q++;
        return !*p;
    }
};
