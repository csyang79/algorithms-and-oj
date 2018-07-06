class Solution {
	public:
		vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
			if (candidates.empty())
				return {};
			vector<vector<int>> result;
			vector<int> cur;
			sort(candidates.begin(), candidates.end());
			dfs(candidates, target, 0, cur, result);
			return result;
		}
		void dfs(const vector<int>& candidates, int target, int start, vector<int>& cur, vector<vector<int>>& result)
		{
			if (target == 0)
			{
				result.push_back(cur);
				return;
			}
			if (target < 0)
				return;
			for (int i = start; i < candidates.size(); ++i)
			{
				if (i != start && candidates[i] == candidates[i - 1])
					continue;
				cur.push_back(candidates[i]);
				dfs(candidates, target - candidates[i], i + 1, cur, result);
				cur.pop_back();
			}
		}
};
