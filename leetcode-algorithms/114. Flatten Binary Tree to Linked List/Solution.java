class Solution {
	public void flatten(TreeNode root) {
		flatten(root, null);
	}
	public TreeNode flatten(TreeNode root, TreeNode tail) {
		if (root == null)
			return tail;
		root.right = flatten(root.left, flatten(root.right, tail));
		root.left = null;
		return root;
	}
}
