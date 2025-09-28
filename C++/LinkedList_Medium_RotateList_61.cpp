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
    ListNode* rotateRight(ListNode* head, int k)
    {
        int count = 1;

        if(head == NULL || head -> next == NULL || k == 0)
        {
            return head;
        }

        ListNode* ptr = head;
        ListNode* p = head;

        while(ptr -> next != NULL)
        {
            count++;
            ptr = ptr -> next;
        }

        if(k%count == 0)
        {
            return head;
        }

        int jumps = count - (k % count) - 1;

        for(int i = 0; i < jumps; i++)
        {
            p = p -> next;
        }

        ListNode* newhead = p -> next;

        p->next = NULL;

        ptr -> next = head;

        return newhead;

    }
};