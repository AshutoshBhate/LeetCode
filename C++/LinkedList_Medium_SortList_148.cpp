//Brute-Force Approach : My Approach

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
    ListNode* sortList(ListNode* head) 
    {
        vector<int> vec_1;
        ListNode* temp = head;
        ListNode* prev;
        ListNode* start;

        while(temp != NULL)
        {
            vec_1.push_back(temp -> val);
            temp = temp -> next;
        }

        sort(vec_1.begin(), vec_1.end());

        if(vec_1.size() == 0)
        {
            return NULL;
        }
        else
        {
            prev = new ListNode(vec_1[0]);
            start = prev;
        }
        for(int i = 1; i < vec_1.size(); i++)
        {
            ListNode* temp = new ListNode(vec_1[i]);
            prev -> next = temp;
            prev = temp;
        }
        
        return start;
    }
};

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

    ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }

    ListNode* mergeHalves(ListNode* leftNode, ListNode* rightNode)
    {
        ListNode* ptr = new ListNode();
        ListNode* temp = ptr;
        while(leftNode != NULL && rightNode != NULL)
        {
            if(leftNode -> val < rightNode -> val)
            {
                temp -> next = leftNode;
                temp = temp -> next;
                leftNode = leftNode -> next;
            }
            else
            {
                temp -> next = rightNode;
                temp = temp -> next;
                rightNode = rightNode -> next;
            }
        }
        if(leftNode != NULL)
        {
            temp -> next = leftNode;
        }
        else
        {
            temp -> next = rightNode;
        }
        
        ListNode* result = ptr -> next;
        delete ptr;
        return result;
    }

    ListNode* sortList(ListNode* head) 
    {
        if(head == NULL || head -> next == NULL)
        {
            return head;
        }

        ListNode* middle = findMiddle(head);
        ListNode* left = head;
        ListNode* right = middle -> next;

        middle -> next = NULL;

        ListNode* leftNode = sortList(left);
        ListNode* rightNode = sortList(right);

        return mergeHalves(leftNode, rightNode);
    }
};
