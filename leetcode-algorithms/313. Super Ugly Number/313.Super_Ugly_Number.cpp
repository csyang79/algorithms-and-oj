class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n, INT_MAX), ptr(primes.size());
        ugly[0] = 1;
        for (int count = 1; count < n; ++count)
        {
            for (int i = 0; i < ptr.size(); ++i)
                ugly[count] = std::min(ugly[count], ugly[ptr[i]] * primes[i]);
            for (int i = 0; i < ptr.size(); ++i)
                if (ugly[count] == ugly[ptr[i]] * primes[i])
                    ++ptr[i];
        }
        return ugly[n - 1];
    }
};
