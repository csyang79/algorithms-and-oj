class NumArray {
public:
    NumArray(vector<int> nums) {
        sum.push_back(0);		//优秀
        for (auto i : nums)
            sum.push_back(sum.back() + i);
    }
    
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
private:
    vector<int> sum;
};

