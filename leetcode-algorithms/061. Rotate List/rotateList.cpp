class Solution {
	public:
		ListNode* rotateRight(ListNode* head, int k) {
			if (!head || !head->next)
				return head;
			ListNode *p = head;
			int len = 0;
			while (p)
			{
				++len;
				p = p->next;
			}
			k %= len;
			if (k == 0)
				return head;
			k = len - k;
			p = head;
			while (--k)
				p = p->next;
			ListNode *q = p->next;
			p->next = nullptr;
			p = head;
			p = q;
			while (p->next)
				p = p->next;
			p->next = head;
			return q;
		}
};
