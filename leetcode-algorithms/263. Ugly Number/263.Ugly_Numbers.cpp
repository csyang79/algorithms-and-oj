class Solution {
public:
    bool isUgly(int num) {
        for (int i = 5; i > 1 && num; --i)
            while (num % i == 0)
                num /= i;
        return num == 1;
    }
};
