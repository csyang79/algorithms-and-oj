/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
	public ListNode rotateRight(ListNode head, int k) {
		if (k == 0 || head == null || head.next == null)
			return head;
		int length = 0;
		for (ListNode p = head; p != null; p = p.next) {
			++length;
		}
		k %= length;
		ListNode behind = head;
		ListNode ahead = head;
		while (k-- != 0) {
			ahead = ahead.next;
		}
		while (ahead.next != null) {
			ahead = ahead.next;
			behind = behind.next;
		}
		ahead.next = head;
		head = behind.next;
		behind.next = null;
		return head;
	}
}
