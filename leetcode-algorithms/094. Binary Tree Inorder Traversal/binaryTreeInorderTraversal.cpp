// iteratoration
class Solution {
	public:
		vector<int> inorderTraversal(TreeNode* root) {
			vector<int> res;
			stack<TreeNode*> stk;
			while (root != nullptr || !stk.empty()) {
				if (root != nullptr) {
					stk.push(root);
					root = root->left;
				} else {
					root = stk.top();
					stk.pop();
					res.push_back(root->val);
					root = root->right;
				}
			}
			return res;
		}
};
