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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr= head;
        int n=0;
        if(head == nullptr){
            return nullptr;
        }
        while(curr!=nullptr){
            n++;
            curr= curr->next;
        }
        while (k%n!=0){
            ListNode* temp = head;
            while(temp->next->next!= nullptr){
                temp=temp->next;
            }
            ListNode* newMode =temp->next;
            temp-> next=nullptr;
            newMode-> next=head;
            head=newMode;
            k--;
        }
        return head;
    }
};