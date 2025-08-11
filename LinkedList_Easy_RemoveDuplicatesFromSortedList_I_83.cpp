//My original Approach : 

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
    ListNode* deleteDuplicates(ListNode* head)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        set<int> mySet;
        vector<int> myVec;

        if(head == NULL)
        {
            return NULL;
        }

        while(head != NULL)
        {
            mySet.insert(head -> val);
            head = head -> next;
        }

        for(auto it : mySet)
        {
            myVec.push_back(it);
        }

        ListNode* p = new ListNode(myVec[0]);
        ListNode* current = p;

        for(int i = 1; i < myVec.size(); i++)
        {
            ListNode* node = new ListNode(myVec[i]);
            current -> next = node;
            current = node;
        }

        return p;
    }
};

//Optimal Approach : 

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
    ListNode* deleteDuplicates(ListNode* head)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        if(head == NULL)
        {
            return NULL;
        }    

        ListNode* curr = head;

        while(curr -> next != NULL)
        {
            if(curr -> val != curr -> next -> val)
            {
                curr = curr -> next;
            }
            else
            {
                curr -> next = curr -> next -> next;
            }
        }

        return head;
    }
};