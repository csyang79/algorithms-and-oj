class Solution {
	public:
		vector<int> postorderTraversal(TreeNode* root) {
			vector<int> res;
			stack<TreeNode*> stk;
			if (root == nullptr) {
				return res;
			}
			TreeNode* pre = root;
			TreeNode* cur = nullptr;
			stk.push(root);
			while (!stk.empty()) {
				cur = stk.top();
				if (cur->left != nullptr && pre != cur->left && pre != cur->right) {
					stk.push(cur->left);
				} else if (cur->right != nullptr && pre != cur->right) {
					stk.push(cur->right);
				} else {
					res.push_back(cur->val);
					stk.pop();
					pre = cur;
				}
			}
			return res;
		}
};
