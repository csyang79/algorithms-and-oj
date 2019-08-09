/*
// Definition for a Node.
class Node {
public int val;
public Node next;
public Node random;

public Node() {}

public Node(int _val,Node _next,Node _random) {
val = _val;
next = _next;
random = _random;
}
};
 */
class Solution {
	public Node copyRandomList(Node head) {
		for (Node p = head; null != p;) {
			Node q = new Node(p.val);
			q.next = p.next;
			p.next = q;
			p = q.next;
		}

		for (Node p = head; null != p;) {
			if (null != p.random) {
				p.next.random = p.random.next;
			}
			p = p.next.next;
		}

		Node dummy = new Node(-1);
		for (Node p = head, q = dummy; null != p;) {
			q.next = p.next;
			q = q.next;
			p.next = q.next;
			p = p.next;
		}
		return dummy.next;
	}
}
