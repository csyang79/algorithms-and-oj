//F(k) - F(k-1) == sum - n*B(k)[0];
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int res = 0;
        int n = A.size();
        int sum = accumulate(A.begin(), A.end(), 0);
        int F = 0;
        for (int i = 0; i < n; ++i)
            F += i * A[i];
        res = F;
        for (int i = 1; i < n; ++i)
        {
            F += sum - n * A[n - i];
            res = F > res ? F : res;
        }
        return res;
    }
};
