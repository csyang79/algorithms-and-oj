// 一般思路
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

// dp代表以i为结尾的最长合法括号序列长度
// dp[i] == {0, s[i] == '(';
//	dp[i - 2] + 2, s[i - 1] == '(';
//	dp[i - dp[i - 1] - 2] + dp[i - 1] + 2, s[i - dp[i - 1] - 1] == '('}
class Solution {
    public int longestValidParentheses(String s) {
        int[] dp = new int[s.length()];
        int res = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (s.charAt(i) == ')') {
                if (s.charAt(i - 1) == '(') {
                    dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
                } else {
                    int t = i - dp[i - 1] - 1;
                    if (t >= 0 && s.charAt(t) == '(') {
                        dp[i] = dp[i - 1] + 2;
                        if (t - 1 >= 0) {
                            dp[i] += dp[t - 1];
                        }
                    }
                }
                res = Math.max(res, dp[i]);
            }
        }
        return res;
    }
}
