// 思路很好的题
class Solution {
	public String countAndSay(int n) {
		// StringBuilder res = "1";是不可以的
		StringBuilder res = new StringBuilder("1");
		int count;
		for (int i = 1; i < n; ++i) {
			count = 1;
			StringBuilder t = new StringBuilder();
			for (int j = 1; j < res.length(); ++j) {
				// 每次遇到新值，将已统计值写入
				if (res.charAt(j) != res.charAt(j - 1)) {
					// char to String:Character.toString(); int + char会得到int
					t.append(count + Character.toString(res.charAt(j - 1)));
					count = 1;
				} else {
					++count;
				}
			} 
			// 最后一次碰到的值未被写入，此时写入
			t.append(count + Character.toString(res.charAt(res.length() - 1)));
			// 不断更新res，下次会用到
			res = t;
		}
		return res.toString();
	}
}
