// stack
class Solution {
	public int longestValidParentheses(String s) {
		Stack<Integer> stack = new Stack<>();
		stack.push(-1);
		int res = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s.charAt(i) == '(') {
				stack.push(i);
			} else {
				stack.pop();
				if (!stack.empty()) {
					res = Math.max(res, (i - stack.peek()));
				} else {
					stack.push(i);
				}
			}
		}
		return res;
	}
}

// 更易理解的思路
class Solution {
	public int longestValidParentheses(String s) {
		Stack<Integer> lefts = new Stack<>();
		int last = -1;
		int res = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s.charAt(i) == '(') {
				lefts.push(i);
			} else {
				if (lefts.empty()) {
					last = i;
				} else {
					lefts.pop();
					if (lefts.empty()) {
						res = Math.max(res, i - last);
					} else {
						res = Math.max(res, i - lefts.peek());
					}
				}
			}
		}
		return res;
	}
}
