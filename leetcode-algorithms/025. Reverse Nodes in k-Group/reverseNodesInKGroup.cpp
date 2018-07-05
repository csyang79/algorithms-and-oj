//头插法，O(n)
class Solution {
	public:
		ListNode* reverseKGroup(ListNode* head, int k) {
			if (!head || k <= 1)
				return head;
			ListNode dummy(-1);
			ListNode *pre = &dummy;
			pre->next = head;
			ListNode *tail = head;
			ListNode *t;
			while (tail && tail->next)
			{
				int i;
				for (i = 1; i < k && tail->next; ++i)
				{
					t = tail->next;
					tail->next = t->next;
					t->next = pre->next;
					pre->next = t;
				}
				if (i != k)
				{
					while (pre->next != tail)
					{
						t = pre->next;
						pre->next = t->next;
						t->next = tail->next;
						tail->next = t;
					}
					return dummy.next;
				}
				pre = tail;
				tail = tail->next;
			}
			return dummy.next;
		}
};
