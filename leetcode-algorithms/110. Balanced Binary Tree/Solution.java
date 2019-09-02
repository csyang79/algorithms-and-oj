// O(nlogn)低效率的方法，求高度重复
// T(n) = 2T(n/2) + O(n)
class Solution {
	public boolean isBalanced(TreeNode root) {
		return root == null ? true : Math.abs(height(root.left) - height(root.right)) <= 1 && isBalanced(root.left) && isBalanced(root.right);
	}
	public int height(TreeNode node) {
		return node == null ? 0 : Math.max(height(node.left), height(node.right)) + 1;
	}
}

// O(n), T(n) = 2T(n/2) + O(1)
class Solution {
	public boolean isBalanced(TreeNode root) {
		return balancedHeight(root) != -1;
	}
	public int balancedHeight(TreeNode node) {
		if (node == null)
			return 0;
		int left = balancedHeight(node.left);
		int right = balancedHeight(node.right);
		if (left == -1 || right == -1 || Math.abs(left - right) > 1)
			return -1;

		return Math.max(left, right) + 1;
	}
}
