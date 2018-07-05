//O(nlogk), divide and conquer
class Solution {
	public:
		ListNode* mergeKLists(vector<ListNode*>& lists) {
			if (lists.empty())
				return nullptr;
			int step = 1;
			while (step < lists.size())
			{
				for (int i = step; i < lists.size(); i += 2 * step)
					lists[i - step] = merge(lists[i - step], lists[i]);
				step *= 2;
			}
			return lists[0];
		}
		ListNode *merge(ListNode *head1, ListNode *head2)
		{
			if (!head1)
				return head2;
			if (!head2)
				return head1;
			ListNode dummy(-1);
			ListNode *pre = &dummy;
			while (head1 && head2)
			{
				if (head1->val < head2->val)
				{
					pre->next = head1;
					head1 = head1->next;
				}
				else
				{
					pre->next = head2;
					head2 = head2->next;
				}
				pre = pre->next;
			}
			if (head1)
				pre->next = head1;
			if (head2)
				pre->next = head2;
			return dummy.next;
		}
};

//priority_queue, O(nlogk)
//note:compare 对象的写法，重载了operator()，并非比较操作符<>
class compare
{
	public:
		bool operator()(ListNode *p, ListNode *q)
		{
			return p->val > q->val;
		}
};
class Solution {
	public:
		ListNode* mergeKLists(vector<ListNode*>& lists) {
			priority_queue<ListNode*, vector<ListNode*>, compare> pq;
			for (auto list : lists)
				if (list != nullptr)
					pq.push(list);
			ListNode dummy(-1);
			ListNode *pre = &dummy;
			while (!pq.empty())
			{
				ListNode *t = pq.top();
				pq.pop();
				pre->next = t;
				pre = pre->next;
				t = t->next;
				if (t)
					pq.push(t);
			}
			return dummy.next;
		}
};
