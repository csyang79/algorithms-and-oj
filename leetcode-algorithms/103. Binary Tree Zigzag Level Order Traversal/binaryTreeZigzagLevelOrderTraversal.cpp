class Solution {
	public:
		vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
			vector<vector<int>> res;
			queue<TreeNode*> q;
			if (root == nullptr) {
				return res;
			}
			q.push(root);
			int curLevel = 0;
			while (!q.empty()) {
				int size = q.size();
				TreeNode *t;
				vector<int> level;
				while (--size >= 0) {
					t = q.front();
					level.push_back(t->val);
					q.pop();
					if (t->left != nullptr) {
						q.push(t->left);
					}
					if (t->right != nullptr) {
						q.push(t->right);
					}
				}
				if ((curLevel & 1) == 1) {
					reverse(level.begin(), level.end());
				}
				res.push_back(level);
				++curLevel;
			}
			return res;
		}
};
