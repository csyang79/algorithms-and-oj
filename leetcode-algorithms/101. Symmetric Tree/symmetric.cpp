// 递归版 
class Solution {
	public:
		bool isSymmetric(TreeNode* root) {
			return root == nullptr || isMirror(root->left, root->right);       
		}
		bool isMirror(TreeNode *left, TreeNode *right) {
			if (left == nullptr || right == nullptr)
				return left == right;
			return left->val == right->val && isMirror(left->left, right->right) && isMirror(left->right,  right->left);
		}
};

// 迭代版，层序思路
class Solution {
	public:
		bool isSymmetric(TreeNode* root) {
			if (!root)
				return true;
			queue<TreeNode*> q;
			q.push(root);
			int size;
			TreeNode *t;
			while (!q.empty()) {
				size = q.size();
				vector<string> strings;
				while (size--) {
					t = q.front();
					q.pop();
					if (t->left) {
						q.push(t->left);
						strings.push_back(std::to_string(t->left->val));
					} else {
						strings.push_back("");
					}
					if (t->right) {
						q.push(t->right);
						strings.push_back(std::to_string(t->right->val));
					}
					else {
						strings.push_back("");
					}
				}
				if (!isSemmetric(strings))
					return false;
			}
			return true;
		}
		bool isSemmetric(const vector<string>& strings) {
			for (int i = 0, j = strings.size() - 1; i < j; ++i, --j)
				if (strings[i] != strings[j])
					return false;
			return true;
		}
};
