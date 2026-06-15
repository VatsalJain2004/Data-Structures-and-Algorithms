
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head -> next)  return NULL;
        if(head -> next -> next == NULL){
            head -> next = NULL;
            return head;
        }

        ListNode *slow = head, *fast = head;
        ListNode *temp = head;
        while(fast && fast -> next){
            temp = slow;
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        temp -> next = slow -> next;
        delete slow; 
        return head;
    }
};