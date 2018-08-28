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
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode* lazy = dummyHead;
        ListNode* notLazy = dummyHead;
        
        while (n > 0 && notLazy->next != NULL) {
            notLazy = notLazy->next;    
            n--;
        }
        
        if (n) {
            return head;
        }
        
        while (notLazy->next != NULL) {
            notLazy = notLazy->next;
            lazy = lazy->next;
        }
        
        ListNode* toDelete = lazy->next;
        lazy->next = lazy->next->next;
        delete toDelete;
        
        head = dummyHead->next;
        delete dummyHead;
        
        return head;
    }
};
