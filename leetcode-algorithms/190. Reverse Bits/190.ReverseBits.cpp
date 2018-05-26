class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; ++i)
            ans |= ((n >> i) & 0x1) << (31 - i);
        return ans;
    }
};

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = ((n & 0xFFFF0000) >> 16) | ((n & 0x0000FFFF) << 16);
        n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
        n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
        n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};


