// 可推广思路，邓俊辉
class Solution {
	public List<Integer> preorderTraversal(TreeNode root) {
		List<Integer> list = new ArrayList<>();
		if (root == null) {
			return list;
		}
		Stack<TreeNode> stack = new Stack<>();
		stack.push(root);
		TreeNode cur;
		while (!stack.empty()) {
			cur = stack.pop();
			while (cur != null) {
				list.add(cur.val);
				if (cur.right != null) {
					stack.push(cur.right);
				}
				cur = cur.left;
			}
		}
		return list;
	}
}

// 一般思路
class Solution {
	public List<Integer> preorderTraversal(TreeNode root) {
		List<Integer> list = new ArrayList<>();
		if (root == null)
			return list;
		Stack<TreeNode> stack = new Stack<>();
		stack.push(root);
		TreeNode cur;
		while (!stack.empty()) {
			cur = stack.pop();
			list.add(cur.val);
			if (cur.right != null)
				stack.push(cur.right);
			if (cur.left != null)
				stack.push(cur.left);
		}
		return list;
	}
}

