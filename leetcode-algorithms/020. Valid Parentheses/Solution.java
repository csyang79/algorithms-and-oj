class Solution {
	public boolean isValid(String s) {
		Stack<Character> stack = new Stack<>();
		for (char c : s.toCharArray()) {
			switch(c) {
				case '(':
				case '{':
				case '[':
					stack.push(c);
					break;
				case ')':
					if (!stack.empty() && stack.peek() == '(') {
						stack.pop();
					} else {
						return false;
					}
					break;
				case ']':
					if (!stack.empty() && stack.peek() == '[') {
						stack.pop();
					} else {
						return false;
					}
					break;
				case '}':
					if (!stack.empty() && stack.peek() == '{') {
						stack.pop();
					} else {
						return false;
					}
					break;
				default:
					return false;
			}
		}
		return stack.empty();
	}
}
