class Solution {
	public:
		void flatten(TreeNode* root) {
			flatten(root, nullptr);
		}
		TreeNode* flatten(TreeNode *root, TreeNode *tail) {
			if (root == nullptr)
				return tail;
			root->right = flatten(root->left, flatten(root->right, tail));
			root->left = nullptr;
			return root;
		}
};
