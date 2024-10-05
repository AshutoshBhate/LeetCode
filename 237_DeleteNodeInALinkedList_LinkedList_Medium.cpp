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
    void deleteNode(ListNode* node)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        if(node == NULL || node -> next == NULL)
        {
            return;
        }
        else
        {
            ListNode* next_node = node -> next;
            node -> val = next_node -> val;
            node -> next = next_node -> next;
            
            delete next_node;
        }
    }
};