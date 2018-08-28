/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* mergeTwoSortedLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* newList = dummy;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                newList->next = list1;
                list1 = list1->next;
            } else {
                newList->next = list2;
                list2 = list2->next;
            }
            newList = newList->next;
        }
        if (list1 != NULL) {
            newList->next = list1;
        } else {
            newList->next = list2;
        }
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
    
    ListNode* mergeKSortedLists(vector<ListNode*>& lists, int low, int high) {
        if (low == high) {
            return lists[low];
        } else {
            int mid = low + (high - low) / 2;
            ListNode* list1 = mergeKSortedLists(lists, low, mid);
            ListNode* list2 = mergeKSortedLists(lists, mid + 1, high);
            return mergeTwoSortedLists(list1, list2);
        }
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        return mergeKSortedLists(lists, 0, (int) lists.size() - 1);
    }
};
