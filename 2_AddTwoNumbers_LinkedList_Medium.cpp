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

/* class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        vector<char> array_1;
        vector<char> array_2;

        while (l1 != NULL) {
            array_1.push_back(l1->val + '0');
            l1 = l1->next;
        }
        while (l2 != NULL) {
            array_2.push_back(l2->val + '0');
            l2 = l2->next;
        }

        reverse(array_1.begin(), array_1.end());
        reverse(array_2.begin(), array_2.end());

        string numStr1(array_1.begin(), array_1.end());
        string numStr2(array_2.begin(), array_2.end());

        long long num1 = stoll(numStr1);
        long long num2 = stoll(numStr2);

        long long result = num1 + num2;
        string LL_List = to_string(result);
        reverse(LL_List.begin(), LL_List.end());

        ListNode* p = new ListNode(LL_List[0] - '0');
        ListNode* current = p;
        ListNode* ptr;

        if (LL_List.size() == 1) {
            return p;
        }

        for (int i = 1; i < LL_List.size(); i++) {
            ptr = new ListNode(LL_List[i] - '0');
            current->next = ptr;
            current = ptr;
        }

        return p;
    }
}; */

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* dummyHead = new ListNode(0); // Create a dummy node to simplify handling
        ListNode* current = dummyHead; // Pointer to build the new list
        int carry = 0; // Variable to store the carry value

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int sum = carry; // Start with the carry

            if (l1 != nullptr)
            {
                sum += l1->val; // Add value from the first list if available
                l1 = l1->next; // Move to the next node
            }

            if (l2 != nullptr)
            {
                sum += l2->val; // Add value from the second list if available
                l2 = l2->next; // Move to the next node
            }

            carry = sum / 10; // Calculate the new carry
            current->next = new ListNode(sum % 10); // Create a new node with the sum's last digit
            current = current->next; // Move to the new node
        }

        return dummyHead->next; // Return the next node of dummy, which is the head of the result list
    }
};
