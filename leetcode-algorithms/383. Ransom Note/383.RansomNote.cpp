class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int dict[256] = {0};
        for (char c : magazine)
            ++dict[c];
        for (char c : ransomNote)
            --dict[c];
        for (int item : dict)
            if (item < 0)
                return false;
        return true;
    }
};
