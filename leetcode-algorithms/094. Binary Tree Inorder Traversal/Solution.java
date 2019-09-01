// 邓俊辉
class Solution {
	public List<Integer> inorderTraversal(TreeNode root) {
		List<Integer> list = new ArrayList<>();
		Stack<TreeNode> stack = new Stack<>();
		while (root != null || !stack.empty()) {
			if (root != null) {
				stack.push(root);
				root = root.left;
			} else {
				root = stack.pop();
				list.add(root.val);
				root = root.right;
			}
		}
		return list;
	}
}
