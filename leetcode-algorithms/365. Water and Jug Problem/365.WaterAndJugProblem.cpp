//http://www.cnblogs.com/grandyang/p/5628836.html
//AOJ0005:gcd(x, y) == gcd(y, x % y), lcm(x, y) == (long long)(x * y) / gcd(x , y)
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || ((x + y >= z) && (z % gcd(x, y)) == 0);
    }
    int gcd(int x, int y)
    {
        for (int t; t = x % y; x = y, y = t);
        return y;
    }
};
