class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> next_greater_element(nums2.size(), -1);

        stack<int> myStack;
        map<int, int> myMap;
        vector<int> answer;

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while(!myStack.empty() && myStack.top() <= nums2[i])
            {
                myStack.pop();
            }
            if (!myStack.empty())
            {
                next_greater_element[i] = myStack.top();
            }

            myStack.push(nums2[i]);
        }

        for(int i = 0; i < nums2.size(); i++)
        {
            myMap[nums2[i]] = next_greater_element[i];
        }
        for(int i = 0; i < nums1.size(); i++)
        {
            answer.push_back(myMap[nums1[i]]);
        }

        return answer;
    }
};