class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* result = dummy;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            result->next = new ListNode(0);
            result = result->next;
            int cur = carry;
            if (l1 != NULL) {
                cur += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                cur += l2->val;
                l2 = l2->next;
            }
            result->val = (cur % 10);
            carry = cur / 10;
        }
        if (carry) {
            result->next = new ListNode(carry);
        }
        return dummy->next;
    }
};
