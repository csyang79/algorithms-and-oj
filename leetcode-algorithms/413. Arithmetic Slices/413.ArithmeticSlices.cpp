class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int cur = 0, sum = 0;
        for (int i = 2; i < a.size(); ++i)
            if (a[i] - a[i - 1] == a[i - 1] - a[i - 2])
            {
                cur += 1;
                sum += cur;
            }
            else
                cur = 0;
        return sum;
    }
};
