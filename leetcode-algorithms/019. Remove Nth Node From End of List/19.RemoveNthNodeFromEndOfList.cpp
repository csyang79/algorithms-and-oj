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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || n <= 0)
            return head;
        ListNode dummy(-1);
        ListNode *pre = &dummy;
        pre->next = head;
        ListNode *ahead = head;
        while (n-- && ahead)
            ahead = ahead->next;
        if (n != -1)
            return head;
        while (ahead)
        {
            pre = pre->next;
            ahead = ahead->next;
        }
        ahead = pre->next;
        pre->next = ahead->next;
        delete ahead;
        return dummy.next;
    }
};
/*
class Solution {			
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode **behind = &head, *ahead = head;
        for (int i = 0; i < n; ++i)
            ahead = ahead->next;
        while (ahead)
        {
            ahead = ahead->next;
            behind = &((*behind)->next);
        }
        *behind = (*behind)->next;
        return head;
    }
};
*/
