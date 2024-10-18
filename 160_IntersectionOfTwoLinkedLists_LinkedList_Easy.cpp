/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        if(headA == NULL || headB == NULL)
        {
            return NULL;
        }

        unordered_set<ListNode*> A_head;
        unordered_set<ListNode*> :: iterator iter;

        while(headA != NULL)
        {
            A_head.insert(headA);
            headA = headA -> next;
        }

        while(headB != NULL)
        {
            iter = A_head.find(headB);
            if(iter != A_head.end())
            {
                return headB;
            }
            else
            {
                headB = headB -> next;
            }
        }

        return NULL;
    }
};