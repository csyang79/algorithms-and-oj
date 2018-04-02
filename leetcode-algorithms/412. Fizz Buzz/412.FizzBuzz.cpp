class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);
        int i = 0;
        while (++i <= n)
        {
            if (i % 3 == 0)
                result[i - 1].append("Fizz");
            if (i % 5 == 0)
                result[i - 1].append("Buzz");
            if (result[i - 1].empty())
                result[i - 1].append(to_string(i));
        }
        return result;
    }
};
