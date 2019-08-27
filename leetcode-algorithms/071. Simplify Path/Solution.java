// stack
class Solution {
	public String simplifyPath(String path) {
		String[] paths = path.split("/");
		StringBuilder sb = new StringBuilder();
		List<String> resList = new ArrayList<>();
		for (String str : paths) {
			if (str.equals(".") || str.equals(""))
				continue;
			if (str.equals("..")) {
				if (resList.size() > 0) {
					resList.remove(resList.size() - 1);
				}
			} else {
				resList.add(str);
			}
		}
		for (String str : resList) {
			sb.append("/" + str);
		}
		return sb.length() == 0 ? "/" : sb.toString();
	}
}
