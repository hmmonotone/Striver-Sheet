// Link to the problem
// https://leetcode.com/problems/palindrome-linked-list/

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
    ListNode* reverse(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        
        ListNode* dummy=NULL;
        ListNode* next=head->next;
        while(next)
        {
            next=head->next;
            head->next=dummy;
            dummy=head;
            head=next;
        }
        return dummy;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return 1;
        
        ListNode* slow=head,*fast=head;
        while(fast->next!=NULL&&fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        fast=reverse(slow->next);
        slow=head;
        while(fast)
        {
            if(fast->val!=slow->val)
            {
                return 0;
            }
            fast=fast->next;
            slow=slow->next;
        }
        return 1;
    }
};