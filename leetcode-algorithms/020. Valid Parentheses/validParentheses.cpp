class Solution {
	public:
		bool isValid(string s) {
			if (s.size() & 1)
				return false;
			stack<char> stk;
			for (char c : s)
			{
				switch(c)
				{
					case '(':
					case '[':
					case '{':
						stk.push(c);
						break;
					case ')':
						if (!stk.empty() && stk.top() == '(')
							stk.pop();
						else
							return false;
						break;
					case ']':
						if (!stk.empty() && stk.top() == '[')
							stk.pop();
						else
							return false;
						break;
					case '}':
						if (!stk.empty() && stk.top() == '{')
							stk.pop();
						else
							return false;
						break;
					default:
						return false;
				}
			}
			return stk.empty();
		}
};
