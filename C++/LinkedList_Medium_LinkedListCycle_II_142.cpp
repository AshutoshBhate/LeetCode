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
    ListNode *detectCycle(ListNode *head)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        map<ListNode*, int> myMap;
        map<ListNode*, int> :: iterator it;
        ListNode* ptr = head;

        while(ptr != NULL)
        {
            it = myMap.find(ptr);
            if(it != myMap.end())
            {
                return ptr;
            }
            else
            {
                myMap[ptr] = ptr -> val;
                ptr = ptr -> next;
            }
        }
        
        return NULL;
    }
};