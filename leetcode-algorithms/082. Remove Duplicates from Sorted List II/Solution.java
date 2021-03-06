/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
	public ListNode deleteDuplicates(ListNode head) {
		ListNode dummy = new ListNode(-1);
		ListNode pre = dummy;
		pre.next = head;
		while (null != head) {
			if (null != head.next && head.val == head.next.val) {
				while (null != head.next && head.val == head.next.val) {
					head.next = head.next.next;
				}
				head = head.next;
				pre.next = head;
			} else {
				head = head.next;     
				pre = pre.next;
			}
		}
		return dummy.next;
	}
}
