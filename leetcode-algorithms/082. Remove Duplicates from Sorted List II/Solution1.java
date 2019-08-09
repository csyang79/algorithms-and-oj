/*
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution1 {
	public ListNode deleteDuplicates(ListNode head) {
		ListNode dummy = new ListNode(-1);
		ListNode p = dummy;
		while (head != null) {
			if (head.next != null && head.val == head.next.val) {
				while (head.next != null && head.val == head.next.val) {
					head.next = head.next.next;
				}
				head = head.next;
			} else {
				p.next = head;
				head = head.next;
				p = p.next;
			}
		}
		p.next = null;
		return dummy.next;
	}
}
