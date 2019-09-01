// 有左子树且未访问过,入栈,有右子树且未访问过,入栈,其他,访问当前节点
class Solution {
	public List<Integer> postorderTraversal(TreeNode root) {
		List<Integer> res = new ArrayList<>();
		Stack<TreeNode> stk = new Stack<>();
		if (root == null)
			return res;
		TreeNode pre = root;
		TreeNode cur = null;
		stk.push(root);
		while (!stk.empty()) {
			cur = stk.peek();
			if (cur.left != null && pre != cur.left && pre != cur.right) {
				stk.push(cur.left);
			} else if (cur.right != null && pre != cur.right) {
				stk.push(cur.right);
			} else {
				res.add(cur.val);
				pre = cur;
				stk.pop();
			}
		}
		return res;
	}
}
