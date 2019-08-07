// 需要用2bit表示出现次数,到3次则清0,a为高位,b为低位,来一个新bit判断是否置位,电路设计
public class Solution {
	public static int singleNumber(int[] nums) {
		int a = 0;
		int b = 0;
		for (int c : nums) {
			int tmp = (a & ~b & ~c) | (~a & b & c);
			b = (~a & b & ~c) | (~a & ~b & c);
			a = tmp;
		}
		// b代表出现1次
		return a;
	}
	public static void main(String[] args) {
		int t = Solution.singleNumber(new int[]{4, 2, 2, 4, 3});
		// 输出4
		System.out.println(t);
	}
}
/*
   a b c a b
   0 0 0 0 0
   0 1 0 0 1	b置位
   1 0 0 1 0	a置位
   0 0 1 0 1	b置位
   0 1 1 1 0	a置位
   1 0 1 0 0
 */
// 标准解法
class Solution {
	public int singleNumber(int[] nums) {
		int a = 0;
		int b = 0;
		for (int c : nums) {
			int tmp = (a & ~b & ~c) | (~a & b & c);
			b = (~a & b & ~c) | (~a & ~b & c);
			a = tmp;
		}
		return b;
	}
}
