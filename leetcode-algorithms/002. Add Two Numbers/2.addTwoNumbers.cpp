/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1, *q = l2;		//缺点：仅循环里用应声明于for循环
        int t = 0, s;
        ListNode dummy(-1);
        ListNode *pre = &dummy;
        while (p || q || t) 
        {
            s = (p ? p->val : 0) + (q ? q->val : 0) + t;	//缺点：改为p == nullptr更具可读性	
            pre->next = new ListNode(s % 10);
            t = s >= 10 ? 1 : 0;
            pre = pre->next;
            p ? p = p->next : p;
            q ? q = q->next : q;
        }
        return dummy.next;
    }
};

//good style
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode *prev = &dummy;
        int carry = 0;
        for (ListNode *p = l1, *q = l2; 
             p != nullptr || q != nullptr;
             p == nullptr ? p : p = p->next, q == nullptr ? q : q = q->next, prev = prev->next)
        { 
            const int a1 = p == nullptr ? 0 : p->val;
            const int a2 = q == nullptr ? 0 : q->val;
            const int value = a1 + a2 + carry;
            carry = value / 10;
            prev->next = new ListNode(value % 10);
        }
        if (carry > 0)
            prev->next = new ListNode(carry);
        return dummy.next;
    }
};
