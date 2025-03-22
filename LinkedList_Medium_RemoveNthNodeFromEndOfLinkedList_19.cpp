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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int count = 1;

        if(head == NULL)
        {
            return head;;
        }
        
        ListNode* ptr = head;
        ListNode* p = head;

        while(ptr -> next != NULL)
        {
            ptr = ptr -> next;
            count++;
        }

        if(count == n)
        {
            // ListNode* temp = head; 
            // head = head->next;
            // delete temp;
            // return head;
            head = head -> next;
            return head;
        }

        for(int i = 0; i < count - n - 1; i++)
        {
            p = p -> next;
        }
        ListNode* nextNode = p -> next;
        p -> next = nextNode -> next;

        delete nextNode;

        return head;
    }
};