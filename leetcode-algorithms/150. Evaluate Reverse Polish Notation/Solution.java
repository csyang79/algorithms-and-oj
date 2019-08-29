class Solution {
	public int evalRPN(String[] tokens) {
		Stack<Integer> stack = new Stack<>();
		int a, b;
		for (String str : tokens) {
			switch (str) {
				case "+":
					b = stack.pop();
					a = stack.pop();
					stack.push(a + b);
					break;
				case "-":
					b = stack.pop();
					a = stack.pop();
					stack.push(a - b);
					break;
				case "*":
					b = stack.pop();
					a = stack.pop();
					stack.push(a * b);
					break;
				case "/":
					b = stack.pop();
					a = stack.pop();
					stack.push(a / b);
					break;
				default:
					stack.push(Integer.parseInt(str));
					break;
			}
		}
		return stack.pop();
	}
}
