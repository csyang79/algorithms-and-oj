class Solution {
	public:
		vector<vector<int>> levelOrder(TreeNode* root) {
			vector<vector<int>> res;
			queue<TreeNode*> q;
			if (root == nullptr) {
				return res;
			}
			q.push(root);
			int level = 0;
			TreeNode *cur;
			TreeNode *last = root;
			while (!q.empty()) {
				if (level >= res.size()) {
					res.push_back(vector<int>());
				}
				cur = q.front();
				q.pop();
				res[level].push_back(cur->val);
				if (cur->left != nullptr) {
					q.push(cur->left);
				}
				if (cur->right != nullptr) {
					q.push(cur->right);
				}
				if (cur == last) {
					++level;
					last = q.back();
				}
			}
			return res;
		}
};
