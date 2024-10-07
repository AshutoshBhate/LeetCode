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
    ListNode* deleteMiddle(ListNode* head)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int count = 1;
        ListNode* p = head;

        if(head == NULL || head -> next == NULL)
        {
            return {};
        }

        while(p -> next != NULL)
        {
            p = p -> next;
            count++;
        }
        ListNode* ptr = head;

        int mid = count/2;

        for(int i = 1; i < mid; i++)
        {
            ptr = ptr -> next;
        }
        ListNode* nextNode = ptr -> next;
        ptr -> next = nextNode -> next;

        delete nextNode;

        return head;
    }
};