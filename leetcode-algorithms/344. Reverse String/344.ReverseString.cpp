class Solution {
public:
    string reverseString(string s) {
        int left = 0, right = s.size();
        while (left < right)
        {
            std::swap(s[left], s[right - 1]);
            ++left;
            --right;
        }
        return s;
    }
};
