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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == NULL) {
                return head;
            }
            temp = temp->next;
        }
        ListNode* prev = NULL;
        ListNode* cur = head;
        for (int i = 0; i < k; i++) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head->next = reverseKGroup(cur, k);
        return prev;
    }
};
