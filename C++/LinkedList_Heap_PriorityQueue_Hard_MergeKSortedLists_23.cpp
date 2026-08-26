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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        if(lists.empty())
        {
            return NULL;
        }

        for(ListNode* head : lists)
        {
            if(head != NULL)
            {
                pq.push({head -> val, head});
            }
        }

        ListNode* dummy = new ListNode();
        ListNode* ptr = dummy;

        while(!pq.empty())
        {
            ListNode* node = pq.top().second;
            dummy -> next = node;
            dummy = node;
            pq.pop();
            if(node -> next != NULL)
            {
                pq.push({node -> next -> val, node -> next});
            }
        }

        if(ptr -> next != NULL)
        {
            return ptr -> next;
        }
        else
        {
            return NULL;
        }

    }
};