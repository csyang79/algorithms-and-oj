// 对奇数层reverse即可
class Solution {
	public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
		List<List<Integer>> list = new ArrayList<>();
		Queue<TreeNode> queue = new LinkedList<>();
		if (root == null) {
			return list;
		}
		queue.offer(root);
		int curLevel = 0;
		while (!queue.isEmpty()) {
			List<Integer> level = new ArrayList<>();
			TreeNode t;
			int count = queue.size();
			while (--count >= 0) {
				t = queue.poll();
				level.add(t.val);
				if (t.left != null) {
					queue.offer(t.left);
				}
				if (t.right != null) {
					queue.offer(t.right);
				}
			}
			if ((curLevel & 1) == 1) {
				Collections.reverse(level);
			}
			list.add(level);
			++curLevel;
		}
		return list;
	}
}

