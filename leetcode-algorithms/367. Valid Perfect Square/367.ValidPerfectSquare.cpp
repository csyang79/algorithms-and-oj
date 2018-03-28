//Newton's method
class Solution {
public:
    bool isPerfectSquare(int num) {
        int64_t sqr = num;
        while (sqr * sqr > num)
            sqr = (sqr + num / sqr) >> 1;
        return sqr * sqr == num;
    }
};
