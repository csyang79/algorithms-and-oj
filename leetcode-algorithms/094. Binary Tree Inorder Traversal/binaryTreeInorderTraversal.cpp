//中序栈
class Solution {
	public:
		vector<int> inorderTraversal(TreeNode* x) {
			stack<TreeNode *> stk;
			vector<int> res;
			while (1)
			{
				if (x)
				{
					stk.push(x);
					x = x->left;
				}
				else if (!stk.empty())
				{
					x = stk.top();
					res.push_back(x->val);
					stk.pop();
					x = x->right;
				}
				else 
					break;
			}
			return res;
		}
};


