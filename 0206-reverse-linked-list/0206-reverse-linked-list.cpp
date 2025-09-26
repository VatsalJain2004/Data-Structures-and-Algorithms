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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head -> next) {
            return head;
        }
        ListNode *dummy = NULL, *next = head -> next;
        while(head) {
            head -> next = dummy;
            dummy = head;
            head = next;
            if(next) {
                next = next -> next;
            }
        } 
        head = dummy;
        return head;
    }
};