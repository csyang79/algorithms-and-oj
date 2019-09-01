//　邓俊辉思路
class Solution {
	public:
		vector<int> preorderTraversal(TreeNode* root) {
			vector<int> res;
			stack<TreeNode*> stk;
			TreeNode *cur = root;
			while (cur || !stk.empty()) {
				if (cur) {
					res.push_back(cur->val);
					if (cur->right) {
						stk.push(cur->right);
					}
					cur = cur->left;
				} else {
					cur = stk.top();
					stk.pop();
				}
			}
			return res;
		}
};
