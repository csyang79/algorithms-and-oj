//O(2^n), dfs，注意start参数的使用
class Solution {
	public:
		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			if (candidates.empty())
				return {};
			sort(candidates.begin(), candidates.end());
			vector<vector<int>> result;
			vector<int> cur; 
			dfs(candidates, target, 0, cur, result);
			return result;
		}
		void dfs(vector<int>& candidates, int target, int start, vector<int> &cur, vector<vector<int>>& result)
		{
			if (target < 0)
				return;
			if (target == 0)
			{
				result.push_back(cur);
				return;
			}
			for (int i = start; i < candidates.size(); ++i)
			{
				cur.push_back(candidates[i]);
				dfs(candidates, target - candidates[i], i, cur, result);
				cur.pop_back();
			}
		}
};
