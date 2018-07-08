//头插法, one pass
class Solution {
	public:
		ListNode* reverseBetween(ListNode* head, int m, int n) {
			ListNode dummy(-1);
			ListNode *pre = &dummy;
			pre->next = head;
			ListNode *tail;
			int l = n - m + 1;
			while (--m)
				pre = pre->next;
			ListNode *cur = pre->next;
			tail = pre->next;
			while (l--)
				tail = tail->next;
			while (cur->next != tail)
			{
				ListNode *t = cur->next;
				cur->next = t->next;
				t->next = pre->next;
				pre->next = t;
			}
			return dummy.next;
		}
};
