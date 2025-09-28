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

    ListNode* findKthNode(ListNode* node, int k)
    {
        while(--k && node != NULL)
        {
            node = node -> next;
        }

        return node;
    }

    ListNode* reverseLinkedList(ListNode* node)
    {
        if(node == NULL || node -> next == NULL)
        {
            return node;
        }

        ListNode* prev = NULL;
        ListNode* front;
        ListNode* temp = node;

        while(temp != NULL)
        {
            front = temp -> next;
            temp -> next = prev;

            prev = temp;
            temp = front;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while(temp != NULL)
        {
            ListNode* kthNode = findKthNode(temp, k);
            if(kthNode == NULL)
            {
                if(prevLast != NULL)
                {
                    prevLast -> next = temp;
                    break;
                }
            }

            ListNode* nextNode = kthNode -> next;
            kthNode -> next = NULL;

            reverseLinkedList(temp);
            if(temp == head)
            {
                head = kthNode;
            }
            else
            {
                prevLast -> next = kthNode;
            }

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};