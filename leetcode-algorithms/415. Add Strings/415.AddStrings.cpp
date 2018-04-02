class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1 == "0" && num2 == "0")
            return "0";
        int m = num1.size(), n = num2.size();
        string result(max(m, n) + 1, '0');
        for (int i = result.size() - 1, x, y, sum, carry = 0; i >= 0; --i)
        {
            --m >= 0 ? x = num1[m] - '0' : x = 0;
            --n >= 0 ? y = num2[n] - '0' : y = 0;
            sum = x + y + carry;
            result[i] = sum % 10 + '0';
            carry = sum / 10;
            if (m < 0 && n < 0)
                break;
        }
        return result.substr(result.find_first_not_of('0'));
    }
};
