//O(n),头插法      
class Solution {
	public:
		ListNode* swapPairs(ListNode* head) {
			if (!head || !head->next)
				return head;
			ListNode dummy(-1);
			ListNode *pre = &dummy;
			pre->next = head;
			ListNode *cur = head;
			while (cur && cur->next)
			{
				pre->next = cur->next;
				cur->next = cur->next->next;
				pre->next->next = cur;
				pre = cur;
				cur = cur->next;
			}
			return dummy.next;
		}
};
