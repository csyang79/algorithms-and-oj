class Solution {
	public:
		ListNode* reverseList(ListNode* head) {
			if (!head || !head->next)
				return head;
			ListNode *t = head;
			ListNode *cur;
			while (head->next) {
				cur = head->next;
				head->next = cur->next;
				cur->next = t;
				t = cur;
			}
			return t;
		}
};
