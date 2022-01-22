// Link to the problem
// https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return 0;
        ListNode* slow=head;
        ListNode* fast=head;
        do{
            slow=slow->next;
            if(fast&&fast->next)
            fast=fast->next->next;
            else
                return 0;
        } while(fast&&fast!=slow);
            
        fast=head;
        while(fast!=slow)
        {
           if(fast==NULL||slow==NULL)
            return 0;
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};