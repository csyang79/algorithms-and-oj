//recursion
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i < 10; ++i)
            dfs(ans, i, n);
        return ans;
    }
    void dfs(vector<int>& ans, int cur, int n)
    {
        if (cur > n)
            return;
        else
        {
            ans.push_back(cur);
            for (int i = 0; i < 10; ++i)
            {
                if (cur * 10 + i > n)			//seem decrease the depth of recursion by 1
                    return ;
                dfs(ans, cur * 10 + i, n);
            }
        }
    }
};
//iteration
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int cur = 1;
        for (int i = 0; i < n; ++i)
        {
            ans.push_back(cur);
            if (cur * 10 <= n)
                cur *= 10;
            else
            {
                if (cur == n)
                    cur /= 10;
                ++cur;
                while (cur % 10 == 0)			//eg.1999->2 not 2000
                    cur /= 10;
            }
        }
        return ans;
    }
};
