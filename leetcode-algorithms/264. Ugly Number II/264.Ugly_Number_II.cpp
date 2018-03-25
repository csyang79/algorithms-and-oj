class Solution {
public:
    int nthUglyNumber(int n) {
        if (n < 7)
            return n;
        vector<int> ugly(n);
        ugly[0] = 1;
        int x = 0, y = 0, z = 0;
        for (int i = 1; i < n; ++i)
        {
            ugly[i] = std::min(ugly[x] * 2, std::min(ugly[y] * 3, ugly[z] * 5));
            if (ugly[i] == ugly[x] * 2)
                ++x;
            if (ugly[i] == ugly[y] * 3)
                ++y;
            if (ugly[i] == ugly[z] * 5)
                ++z;
        }
        return ugly[n - 1];
    }
};

