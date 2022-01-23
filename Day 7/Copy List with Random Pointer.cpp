// Link to the problem:
// https://leetcode.com/problems/rotate-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
	unordered_map<Node*, Node*> mp;

	Node* pFakeFirst = new Node(-1);
	Node* pNewCurr = pFakeFirst;

	while (nullptr != head)
	{
		if (mp.end() == mp.find(head))
		{
			Node* pTemp = new Node(head->val);
			mp[head] = pTemp;
			pNewCurr->next = pTemp;
		}
		else
		{
			pNewCurr->next = mp[head];
		}

		pNewCurr = pNewCurr->next;

		if (nullptr != head->random)
		{
			if (mp.end() == mp.find(head->random))
			{
				Node* pNewRandom = new Node(head->random->val);
				mp[head->random] = pNewRandom;
				pNewCurr->random = pNewRandom;
			}
			else
			{
				pNewCurr->random = mp[head->random];
			}

		}

		if (nullptr != head->next)
		{
			if (mp.end() == mp.find(head->next))
			{
				Node* pNewNext = new Node(head->next->val);
				mp[head->next] = pNewNext;
				pNewCurr->next = pNewNext;
			}
			else
			{
				pNewCurr->next = mp[head->next];
			}
		}

		head = head->next;
	}

	return pFakeFirst->next;
    }
};