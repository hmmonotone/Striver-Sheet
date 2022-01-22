// Link to the problem
// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
            
    if(head == NULL||head->next == NULL) 
        return head;
    
    
    ListNode* dummy = new ListNode();
    dummy->next = head;
    
    ListNode* pre = dummy;
    ListNode* cur = head;
    ListNode* nex = dummy;
    int l=1;
    while(cur->next){
        cur=cur->next;
        l++;
    }    
    cur=dummy;
    while(l >= k) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        l-=k;
    }
    return dummy->next;
    }
};