// 慢的解法
/*
class Solution {
	public List<List<String>> groupAnagrams(String[] strs) {
		List<List<String>> res = new ArrayList<>();
		Map<String, ArrayList<String>> map = new HashMap<>();
		String t;
		for (String str : strs) {
			t = sortString(str);
			if (!map.containsKey(t)) {
				map.put(t, new ArrayList<String>());
			}
			map.get(t).add(str);
		}
		map.forEach((k, v) -> res.add(v));
		return res;
	}
	private static String sortString(String str) {
		char[] charArr = str.toCharArray();
		Arrays.sort(charArr);
		return new String(charArr);
	}
}*/

class Solution {
	public List<List<String>> groupAnagrams(String[] strs) {
		List<List<String>> res = new ArrayList<>();
		Map<String, Integer> map = new HashMap<>();
		String tmp;
		for (String str : strs) {
			tmp = sortString(str);
			if (!map.containsKey(tmp)) {
				map.put(tmp, res.size());
				res.add(new ArrayList<String>());
			}
			res.get(map.get(tmp)).add(str);
		}
		return res;

	}
	private static String sortString(String str) {
		char[] arr = str.toCharArray();
		Arrays.sort(arr);
		return new String(arr);
	}
}
