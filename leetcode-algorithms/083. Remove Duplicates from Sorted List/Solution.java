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
		ListNode cur = head;
		while (null != cur) {
			if (null != cur.next && cur.val == cur.next.val) {
				while (null != cur.next && cur.val == cur.next.val) {
					cur.next = cur.next.next;
				}
			}
			cur = cur.next;
		}
		return head;
	}
}
