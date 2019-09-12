// 递归版
class Solution {
	public boolean isSymmetric(TreeNode root) {
		return root == null || isMirror(root.left, root.right);
	}
	public boolean isMirror(TreeNode left, TreeNode right) {
		if (left == null || right == null)
			return left == right;
		return left.val == right.val && isMirror(left.right, right.left) && isMirror(left.left, right.right);
	}
}

// 迭代版
class Solution {
	public boolean isSymmetric(TreeNode root) {
		if (root == null)
			return true;
		Queue<TreeNode> q = new LinkedList();
		TreeNode t;
		q.offer(root);
		while (!q.isEmpty()) {
			List<Object> tmpList = new ArrayList<>();
			int size = q.size();
			while (size-- != 0) {
				t = q.poll();
				if (t.left != null) {
					tmpList.add(t.left.val);
					q.offer(t.left);
				} else {
					tmpList.add("");
				}
				if (t.right != null) {
					tmpList.add(t.right.val);
					q.offer(t.right);
				} else {
					tmpList.add("");
				}
			}
			if (!isSymmetric(tmpList))
				return false;
		}
		return true;
	}
	public boolean isSymmetric(List<Object> list) {
		for (int i = 0, j = list.size() - 1; i < j; ++i, --j)
			if (list.get(i) != list.get(j))
				return false;
		return true;
	}
}
