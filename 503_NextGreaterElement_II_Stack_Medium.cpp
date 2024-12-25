class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int x = nums.size();
        vector<int> next_greater_element(2 * x, -1);
        stack<int> myStack;
        vector<int> answer;

        for(int i = 0; i < x; i++)
        {
            nums.push_back(nums[i]);
        }    

        for(int i = nums.size() - 1; i >= 0; i--)
        {
            while(!myStack.empty() && nums[i] >= myStack.top())
            {
                myStack.pop();
            }
            if (!myStack.empty())
            {
                next_greater_element[i] = myStack.top();
            }
            
            myStack.push(nums[i]);
        }

        for(int i = 0; i < x; i++)
        {
            answer.push_back(next_greater_element[i]);
        }

        return answer;
    }
};