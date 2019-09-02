// solution1
class Solution {
	public List<List<Integer>> levelOrder(TreeNode root) {
		List<List<Integer>> list = new ArrayList<>();
		LinkedList<TreeNode> linkedList = new LinkedList<>();
		if (root == null) {
			return list;
		}
		linkedList.addFirst(root);
		int level = 0;
		TreeNode last = root;
		TreeNode cur;
		while (!linkedList.isEmpty()) {
			if (level >= list.size()) {
				list.add(new ArrayList<>());
			}
			cur = linkedList.removeFirst();
			list.get(level).add(cur.val);
			if (cur.left != null) {
				linkedList.add(cur.left);
			}
			if (cur.right != null) {
				linkedList.add(cur.right);
			}
			if (last == cur) {
				++level;
				last = linkedList.peekLast();
			}
		}
		return list;
	}
}

// solution2
class Solution {
	public List<List<Integer>> levelOrder(TreeNode root) {
		List<List<Integer>> list = new ArrayList<>();
		Queue<TreeNode> queue = new LinkedList<>();
		if (root == null) {
			return list;
		}
		queue.offer(root);
		while (!queue.isEmpty()) {
			TreeNode t;
			List<Integer> level = new ArrayList<>();
			int count = queue.size();
			for (int i = 0; i < count; ++i) {
				t = queue.poll();
				level.add(t.val);
				if (t.left != null) {
					queue.offer(t.left);
				}
				if (t.right != null) {
					queue.offer(t.right);
				}
			}
			list.add(level);
		}
		return list;
	}
}
