class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        int n = citations.size();
        int low = 0, high = citations.size() - 1, mid;
        while (low < high)
        {
            mid = low + (high - low) / 2;
            if (citations[mid] < n - mid)
                low = mid + 1;
            else
                high = mid;
        }
        return citations[low] == 0 ? 0 : n - low;
    }
};
