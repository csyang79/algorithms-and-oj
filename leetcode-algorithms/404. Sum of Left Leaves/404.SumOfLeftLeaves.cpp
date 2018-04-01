//my version
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root || !root->left && !root->right)
            return 0;
        int res = 0;
        sum(root, 1, res);
        return res;
    }
    void sum(TreeNode *x, bool left, int& res)
    {
        if (!x->left && !x->right)
        {
            if (left)
                res += x->val;
            return;
        }
        if (x->left)
            sum(x->left, 1, res);
        if (x->right)
            sum(x->right, 0, res);
    }
};

//more clear
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;
        if (root->left && !root->left->left && !root->left->right)
            return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
