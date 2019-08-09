/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
	public ListNode swapPairs(ListNode head) {
		if (null == head || null == head.next) {
			return head;
		}
		ListNode dummy = new ListNode(-1);
		ListNode pre = dummy;
		ListNode cur = head;
		while (null != cur && null != cur.next) {
			pre.next = cur.next;
			cur.next = cur.next.next;
			pre.next.next = cur;
			pre = cur;
			cur = cur.next;
		}
		return dummy.next;
	}
}
