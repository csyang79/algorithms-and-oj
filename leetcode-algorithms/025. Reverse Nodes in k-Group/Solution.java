/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
// 将要头插或尾插的节点声明为t,然后循环处理
class Solution {
	public ListNode reverseKGroup(ListNode head, int k) {
		if (null == head || null == head.next || k < 2) 
			return head;
		ListNode dummy = new ListNode(-1);
		ListNode pre = dummy;
		ListNode cur = head;
		pre.next = head;
		ListNode t;
		while (null != cur && null != cur.next) {
			int i = 1;
			for (; i < k && null != cur.next; ++i) {
				t = cur.next;
				cur.next = t.next;
				t.next = pre.next;
				pre.next = t;
			}
			if (i != k) {
				while (pre.next != cur) {
					t = pre.next;
					pre.next = t.next;
					t.next = cur.next;
					cur.next = t;
				}
			}
			pre = cur;
			cur = cur.next;
		}
		return dummy.next;
	}
}
