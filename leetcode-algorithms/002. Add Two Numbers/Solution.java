/*
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		ListNode dummy = new ListNode(-1);
		ListNode cur = dummy;
		int carry = 0;
		for (ListNode p = l1, q = l2;
				p != null || q != null;
				p = p == null ? p : p.next, q = q == null ? q : q.next, cur = cur.next) {
			final int a = p == null ? 0 : p.val;
			final int b = q == null ? 0 : q.val;
			final int sum = a + b + carry;
			cur.next = new ListNode(sum % 10);
			carry = sum / 10;
		}
		if (carry == 1)
			cur.next = new ListNode(1);
		return dummy.next;
	}
}
