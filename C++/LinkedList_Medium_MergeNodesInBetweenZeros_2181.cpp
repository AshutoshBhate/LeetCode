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
    ListNode* mergeNodes(ListNode* head)
    {   
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        head = head -> next;
        ListNode* newHead = new ListNode(0);
        ListNode* dummy = newHead;
        
        int addition = 0;

        while(head != NULL)
        {
            if(head -> val == 0)
            {
                ListNode* newNode = new ListNode(addition);
                newHead -> next = newNode;
                newHead = newNode;

                addition = 0;
            }

            addition += head -> val;
            head = head -> next;
        }

        return dummy -> next;
    }
};