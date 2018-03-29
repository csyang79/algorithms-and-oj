// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n, mid;
        for ( ; ; )
        {
            mid = left + (right - left) / 2;			//in case of overflow
            int t = guess(mid);
            if (t > 0)
                left = mid + 1;
            else if (t < 0)
                right = mid - 1;
            else
                return mid;
        }
    }
};
