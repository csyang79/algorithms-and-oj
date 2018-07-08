//很直白，加个dummy
class Solution {
	public:
		ListNode* deleteDuplicates(ListNode* head) {
			if (!head || !head->next)
				return head;
			ListNode dummy(-1);
			ListNode *pre = &dummy;
			pre->next = head;
			ListNode *t;
			while (pre->next)
			{
				if (pre->next->next && pre->next->val == pre->next->next->val)
				{
					while (pre->next->next && pre->next->next->val == pre->next->val)
					{
						t = pre->next->next;
						pre->next->next = t->next;
						delete t;
					}
					t = pre->next;
					pre->next = t->next;
					delete t;
				}
				else
					pre = pre->next;
			}
			return dummy.next;
		}
};
