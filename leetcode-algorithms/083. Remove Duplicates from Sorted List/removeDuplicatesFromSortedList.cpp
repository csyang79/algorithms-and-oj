//简单的要写的简洁
class Solution {
	public:
		ListNode* deleteDuplicates(ListNode* head) {
			if (!head || !head->next)
				return head;
			ListNode *p = head;
			while (p->next)
			{
				if (p->next->val == p->val)
				{
					ListNode *t = p->next;
					p->next = t->next;
					delete t;
				}
				else
					p = p->next;
			}
			return head;
		}
};
