/*
 * Key Pattern: Circular Array + Direct Indexing
 * - Constraints: 
 *   1. Elements CAN REPEAT (duplicates allowed -> direct answers[i] indexing, no Hash Map).
 *   2. Array is CIRCULAR (wraps around to index 0).
 * - Strategy:
 *   - Simulate circular array by doubling array size (or looping 2*N times using i % N).
 *   - Assign result directly to next_greater_element[i] by position to handle duplicates.
 */

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