class Solution {
public:
    Solution(vector<int> nums) : arr(nums), ori(nums) {
    
    }
    vector<int> reset() {
        return arr = ori;
    }
    vector<int> shuffle() {
        int pos;
        for (int i = 0; i < arr.size(); ++i)
        {
            pos = rand() % (i + 1);				//note
            std::swap(arr[i], arr[pos]);
        }
        return arr;
    }
private:
    vector<int> arr, ori;
};
