//reservoir sampling
class Solution {
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int ans = head->val;
        int i = 2;
        ListNode *p = head->next;
        while(p)
        {
            int tmp = rand() % i;
            if (tmp == 1)
                ans = p->val;
            p = p->next;
            ++i;
        }
        return ans;
    }
private:
    ListNode *head;
};

//naive solution
class Solution {
public:
    Solution(ListNode* head) {
        this->head = head;
        len = 0;
        for (ListNode *p = head; p; p = p->next, ++len);
    }
    
    int getRandom() {
        int random = rand() % len;
        ListNode *p = head;
        for (; random; --random, p = p->next);
        return p->val;
    }
private:
    ListNode *head;
    int len;
};


