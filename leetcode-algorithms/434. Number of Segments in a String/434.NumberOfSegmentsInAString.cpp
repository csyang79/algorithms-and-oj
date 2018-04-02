class Solution {
public:
    int countSegments(string s) {
        istringstream stream(s);
        string word;
        int res = 0;
        while(stream >> word)
            ++res;
        return res;
    }
};
