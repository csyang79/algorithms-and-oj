class Solution {
public:
    int arrangeCoins(int n) {
        long res = 1;
        while (res * (res + 1) <= (1ll * n << 1))
            res += 1;
        return res - 1;
    }
};

//sizeof(double) == 8, sizeof(int) == 4, int to double can ignore overflow
class Solution {
public:
    int arrangeCoins(int n) {
        return sqrt(0.25 + static_cast<double>(n) * 2) - 0.5;    
    }
};
