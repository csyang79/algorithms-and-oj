class Solution {
private:
    const int divisor = 1337;
    int powmod(int a, int k)
    {
        if (k == 0)
            return 1;
        return powmod(a, k - 1) * (a % divisor) % divisor;
    }
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty())
            return 1;
        int back = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, back) % divisor;
    }
};
