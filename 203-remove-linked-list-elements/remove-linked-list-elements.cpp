class Solution {
public:
    ListNode* removeElements(ListNode* head, int T) {
        ListNode *dummy = new ListNode(-1, head), *prev = dummy;
        for(;head; head = head -> next) 
            if(head -> val != T) 
                prev = head;                       // just update prev node
            else                                   // current node needs to be deleted
				prev -> next = head -> next;      
        return dummy -> next;                     
    }
};