//Euler Seive
int primes[1000010];
bool notPrime[10000010];
int cntp;
class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        SeivePrime(n - 1);
        for (int i = 2; i < n; ++i)
            if (!notPrime[i])
                ++ans;
        return ans;
    }
    void SeivePrime(int n)
    {
        long long t;
        for (int i = 2; i <= n; ++i)
        {
            if (!notPrime[i])
                primes[cntp++] = i;
            for (int j = 0; j < cntp && (t = 1ll * primes[j] * i) <= n; ++j)
            {
                notPrime[t] = true;
                if (i % primes[j] == 0)
                    break;
            }
        }
    }
};
