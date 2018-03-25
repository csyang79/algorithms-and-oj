class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n);
        ugly[0] = 1;
        vector<int> exp(primes.size());
        for (int count = 1, min_val; count < n; ++count)
        {
            min_val = INT_MAX;
            for (int i = 0; i < primes.size(); ++i)
                    min_val = std::min(min_val, ugly[exp[i]] * primes[i]);
            ugly[count] = min_val;
            for (int i = 0; i < exp.size(); ++i)
                if (ugly[count] == ugly[exp[i]] * primes[i])
                    ++exp[i];
        }
        return ugly[n - 1];
    }
};

