/*
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
	public ListNode deleteDuplicates(ListNode head) {
		if (head == null)
			return null;
		ListNode newHead = head;
		ListNode p = newHead;
		while (head.next != null) {
			if (head.next.val != head.val) {
				p.next = head.next;
				p = p.next;
			}
			head = head.next;
		}
		p.next = null;
		return newHead;
	}
}
