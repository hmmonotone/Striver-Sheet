// Link to the problem:
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
        if(head==NULL)
            return NULL;
        
        ListNode* temp=NULL;
        while(head!=NULL)
        {
            ListNode* t=head->next;
            head->next=temp;
            temp=head;
            head=t;
        }
        return temp;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head=reverseList(head);
        ListNode* t=head;
        if(n==1)
        {
            head=head->next;
            return reverseList(head);
        }
        for(int i=1;i<n-1;i++)
        {
            t=t->next;
        }
        if(t&&t->next&&t->next->next)
        {
            t->next=t->next->next;
        }
        else if(t&&t->next)
            t->next=NULL;
        
        
        return reverseList(head);
    }
};