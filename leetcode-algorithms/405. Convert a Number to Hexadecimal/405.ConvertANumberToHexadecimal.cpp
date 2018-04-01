//normal solution
class Solution {
public:
    string toHex(int numo) {
        if (numo == 0)
            return "0";
        string hex = "0123456789abcdef";
        unsigned int num = numo;			//note
        string ans;
        while (num)
        {
            ans.push_back(hex[num % 16]);
            num /= 16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }   
};

//for 2^n 
class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        string hex = "0123456789abcdef";					
        string res;
        int count = 0;
        while (count++ < 8)		//note: shift right arithmetic, don't use while(num), TLE
        {
            res.push_back(hex[num & 0xf]);					
            num >>= 4;
        }
        reverse(res.begin(), res.end());
        return res.substr(res.find_first_not_of('0'));
    }
};

//by haoel, don't need reverse
class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        unsigned int x = num;
        string result;
        while (x)
        {
            int t = x & 15;
            char c;
            if (t < 10)
                c = t + '0';
            else
                c = 'a' + t - 10;
            result = c + result;
            x /= 16;
        }
        return result;
    }
};
