//注意最后pre2->next = nullptr，此算法可用于链表快排
class Solution {
	public:
		ListNode* partition(ListNode* head, int x) {
			ListNode dummy1(-1);
			ListNode dummy2(-1);
			ListNode *pre1 = &dummy1;
			ListNode *pre2 = &dummy2;
			while (head)
			{
				if (head->val < x)
				{
					pre1->next = head;
					pre1 = pre1->next;
				}
				else
				{
					pre2->next = head;
					pre2 = pre2->next;
				}
				head = head->next;
			}
			pre1->next = dummy2.next;
			pre2->next = nullptr;
			return dummy1.next;
		}
};
