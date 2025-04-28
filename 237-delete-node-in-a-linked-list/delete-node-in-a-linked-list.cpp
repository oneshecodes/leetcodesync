class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == nullptr || node->next == nullptr) return; // Edge case: last node can't be deleted this way

        node->val = node->next->val; // Copy next node's value
        node->next = node->next->next; // Skip the next node, effectively deleting it
    }
};