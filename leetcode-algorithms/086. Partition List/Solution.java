/*
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
	public ListNode partition(ListNode head, int x) {
		ListNode head1 = new ListNode(-1);
		ListNode head2 = new ListNode(-1);
		ListNode p = head1;
		ListNode q = head2;
		for (; head != null; head = head.next) {
			if (head.val < x) {
				p.next = head;
				p = p.next;
			} else {
				q.next = head;
				q = q.next;
			}
		}
		p.next = head2.next;
		q.next = null;
		return head1.next;
	}
}
