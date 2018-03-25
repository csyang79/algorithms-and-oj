class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1)
            return {0};
        vector<int> ans;
        vector<unordered_set<int>> graph(n);
        queue<int> q;
        for (auto edge : edges)
        {
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }
        for (int i = 0; i < graph.size(); ++i)
            if (graph[i].size() == 1)
                q.push(i);
        while (n > 2)
        {
            int size = q.size();
            n -= size;
            for (int i = 0; i < size; ++i)
            {
                int t = q.front();
                q.pop();
                for (auto a : graph[t])
                {
                    graph[a].erase(t);
                    if (graph[a].size() == 1)
                        q.push(a);
                }
            }
        }
        while (!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
