//naive solution
class Solution {
public:
    int integerReplacement(long n) {
        if (n < 3)
            return n - 1;
        if (n % 2 == 0)
            return integerReplacement(n / 2) + 1;
        else
            return min(integerReplacement(n + 1), integerReplacement(n - 1)) + 1;
    }
};

//even : n / 2, odd : to decrease more 1, in binary presentation, end with 11 except 3 incre while others decre
class Solution {
public:
    int integerReplacement(long n) {
        if (n < 3)
            return n - 1;
        if (n % 2 == 0)
            return integerReplacement(n / 2) + 1;
        else if (n != 3 && (n + 1) % 4 == 0)
            return integerReplacement(n + 1) + 1;
        else
            return integerReplacement(n - 1) + 1;
    }
};

//iteration
class Solution {
public:
    int integerReplacement(int nn) {
        int64_t n = static_cast<int64_t>(nn);		//in case of 2147483647, unsigned int also be ok
        int cnt = 0;
        while (n > 1)
        {
            if ((n & 1) == 0)
                n >>= 1;
            else if (n == 3 || (n & 2) == 0)
                --n;
            else
                ++n;
            ++cnt;
        }
        return cnt;
    }
};
