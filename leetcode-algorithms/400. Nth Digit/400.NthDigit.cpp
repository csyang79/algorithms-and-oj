class Solution {
public:
    int findNthDigit(int n) {
        int len = 1;
        int64_t count = 9;
        int start = 1;
        while (n > len * count)
        {
            n -= len * count;
            count *= 10;
            ++len;
            start *= 10;
        }
        string num = to_string(start + (n - 1) / len);
        return num[(n - 1) % len] - '0';
        
    }
};
