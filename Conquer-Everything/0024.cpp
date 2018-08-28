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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* listPtr = dummy;
        
        while (listPtr->next != NULL && listPtr->next->next != NULL) {
            ListNode* first = listPtr->next;
            ListNode* second = listPtr->next->next;
            
            first->next = second->next;
            second->next = first;
            listPtr->next = second;
            
            listPtr = first;
        }
        
        head = dummy->next;
        delete dummy;
        return head;
    }
};
