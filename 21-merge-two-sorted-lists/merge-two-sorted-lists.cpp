/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to start the merged list.
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Loop until one or both lists are exhausted.
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        // Append any remaining elements.
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        
        // dummy.next points to the head of the merged list.
        return dummy.next;
    }
};
