// T(n) = 2T(n / 2) + O(1) 
class Solution {
	public:
		bool isBalanced(TreeNode* root) {
			return balancedHeight(root) != -1;
		}
		int balancedHeight(TreeNode* node) {
			if (node == nullptr) {
				return 0;
			}
			int left = balancedHeight(node->left);
			int right = balancedHeight(node->right);
			if (left == -1 || right == -1 || std::abs(left - right) > 1)
				return -1;
			return std::max(left, right) + 1;
		}
};
