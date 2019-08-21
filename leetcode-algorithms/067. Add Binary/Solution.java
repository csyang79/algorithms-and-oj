class Solution {
    public String addBinary(String a, String b) {
        StringBuilder res = new StringBuilder();
        res.setLength(Math.max(a.length(), b.length()));
        int carry = 0;
        int digit1, digit2;
        int k = res.length() - 1;
        int sum;
        for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; --i, --j) {
            digit1 = i >= 0 ? a.charAt(i) - '0' : 0;
            digit2 = j >= 0 ? b.charAt(j) - '0' : 0;
            sum = digit1 + digit2 + carry;
            carry = sum / 2;
	    // int to char
            res.setCharAt(k--, (char)(sum % 2 + '0'));            
        }
        return carry == 1 ? "1" + res.toString() : res.toString();
    }
}
