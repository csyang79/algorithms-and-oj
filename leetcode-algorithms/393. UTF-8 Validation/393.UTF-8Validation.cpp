class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for (int num : data)
        {
            if (count == 0)
            {
                if ((num >> 5) == 6)
                    count = 1;
                else if ((num >> 4) == 14)
                    count = 2;
                else if ((num >> 3) == 30)
                    count = 3;
                else if (num >> 7)
                    return false;
            }
            else
            {
                if ((num >> 6) != 2)
                    return false;
                --count;
            }
        }
        return count == 0;
    }
};
