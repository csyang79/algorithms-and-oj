//iteratoration
class Solution
{
public:
	vector<int> inorderTraversal(TreeNode * x)
	{
		vector<int> res;
		if (x)
		{
			stack<TreeNode*> stk;
			while (x || !stk.empty())
			{
				if (x)
				{
					stk.push(x);
					x = x->left;
				}
				else
				{
					x = stk.top();
					stk.pop();		
					res.push_back(x->val);
					x = x->right;
				}
			}
		}
		return res;
	}
};
//recursion
class Solution
{
public:
	vector<int> res;
	vector<int> inorderTraversal(TreeNode *x)
	{
		if (x)
		{
			inorderTraversal(x->left);
			res.push_back(x->val);
			inorderTraversal(x->right);
		}
		return res;
	}
};

