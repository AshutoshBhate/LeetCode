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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        if(list1 == NULL)
        {
            return list2;
        }  
        if(list2 == NULL)
        {
            return list1;
        }

        ListNode* head = NULL;
        ListNode* start = NULL;

        while(list1 != NULL && list2 != NULL)
        {
            if(list1 -> val < list2 -> val)
            {
                ListNode* node = list1;
                list1 = list1 -> next;
                node -> next = NULL;
                if(head == NULL)
                {
                    head = node;
                    start = head;
                }
                else
                {
                    head -> next = node;
                    head = head -> next;
                }
               
            }
            else
            {
                ListNode* node = list2;
                list2 = list2 -> next;
                node -> next = NULL;
                if(head == NULL)
                {
                    head = node;
                    start = head;
                }
                else
                {
                    head -> next = node;
                    head = head -> next;
                }
            }
        }
        
        while(list1 != NULL)
        {
            ListNode* node = list1;
            list1 = list1 -> next;
            node -> next = NULL;

            head -> next = node;
            
            head = head -> next;
        }
        while(list2 != NULL)
        {
            ListNode* node = list2;
            list2 = list2 -> next;
            node -> next = NULL;

            head -> next = node;
            
            head = head -> next;
        }

        return start;

    }
};