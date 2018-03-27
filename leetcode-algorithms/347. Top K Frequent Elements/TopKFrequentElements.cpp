//O(n) using bucket sort 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, size_t> unmap;
        for (int num : nums)
            ++unmap[num];
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto p : unmap)
            buckets[p.second].push_back(p.first);
        vector<int> ans;
        for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i)
            for (auto j : buckets[i])
            {
                ans.push_back(j);
                if (ans.size() == k)
                    break;
            }
        return ans;
    }
};

/*O(nlogk) using unordered_map and min_heap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, size_t> unmap;
        for (int num : nums)
            ++unmap[num];
        priority_queue<pair<size_t, int>, vector<pair<size_t, int>>, greater<pair<size_t, int>>> pq;
        for (auto it = unmap.begin(); it != unmap.end(); ++it)
        {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
*/
/*O(nlog(n-k)) using unordered_map and max_heap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> unmap;
        for (int num : nums)
            ++unmap[num];
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        for (auto it = unmap.begin(); it != unmap.end(); ++it)
        {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > static_cast<int>(unmap.size()) - k)
            {
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};
*/
