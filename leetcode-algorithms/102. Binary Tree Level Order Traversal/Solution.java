class Solution {
	public List<List<Integer>> levelOrder(TreeNode root) {
		List<List<Integer>> res = new ArrayList<>();
		LinkedList<TreeNode> queue = new LinkedList<>();
		if (root == null) {
			return res;
		}
		queue.offer(root);
		int level = 0;
		TreeNode last = root;
		TreeNode cur;
		res.add(new ArrayList<>());
		while (!queue.isEmpty()) {
			cur = queue.poll();
			res.get(level).add(cur.val);
			if (cur.left != null) {
				queue.offer(cur.left);
			}
			if (cur.right != null) {
				queue.offer(cur.right);
			}
			if (cur == last) {
				++level;
				last = queue.peekLast();
				if (!queue.isEmpty()) {
					res.add(new ArrayList<>());
				}
			} 
		}
		return res;
	}
}
