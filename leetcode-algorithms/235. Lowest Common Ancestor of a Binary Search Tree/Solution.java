// O(log(n))
class Solution {
	public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
		while ((root.val - p.val) * (q.val - root.val) < 0)
			root = root.val < p.val ? root.right : root.left;
		return root;
	}
}
