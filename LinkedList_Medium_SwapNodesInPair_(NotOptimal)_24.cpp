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
    ListNode* swapPairs(ListNode* head)
    {
        if(head == NULL)
        {
            return head;
        }

        ListNode* ptr = head;

        vector<int> linkarray;

        while(ptr != NULL)
        {
            linkarray.push_back(ptr -> val);
            ptr = ptr -> next;
        }

        int i = 1;
        while(i <= linkarray.size() - 1)
        {
            swap(linkarray[i - 1], linkarray[i]);
            i = i + 2;
        }

        ListNode* newhead = new ListNode(linkarray[0]);
        ListNode* current = newhead;
        
        if(linkarray.size() == 1)
        {
            return newhead;
        }
        
        ListNode* p;
        for(int i = 1; i < linkarray.size(); i++)
        {
            p = new ListNode(linkarray[i]);
            current -> next = p;
            current = p;
        }

        return newhead;
    }
};