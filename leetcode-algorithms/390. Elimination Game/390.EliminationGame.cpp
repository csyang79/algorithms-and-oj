//1,2,3...n to 2(1,2,3...n/2),then get answer
class Solution {
public:
    int lastRemaining(int n) {
        return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
    }
};

//another solution
class Solution {
public:
    int lastRemaining(int n) {
        bool left = 1;
        int remaining = n, step = 1,head = 1;
        while (remaining > 1)
        {
            if (left || remaining % 2 == 1)
                head += step;
            remaining /= 2;
            step *= 2;
            left = !left;
        }
        return head;
    }
};
