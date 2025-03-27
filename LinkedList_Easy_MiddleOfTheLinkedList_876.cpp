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
    ListNode* middleNode(ListNode* head)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int count = 1;

        if(head == NULL || head -> next == NULL)
        {
            return head;
        }

        ListNode* ptr = head;
        while(ptr -> next != NULL)
        {
            ptr = ptr -> next;
            count++;
        }

        count = count / 2;

        ListNode* p = head;
        for(int i = 0; i < count; i++)
        {
            p = p -> next;
        }

        return p;
    }

};