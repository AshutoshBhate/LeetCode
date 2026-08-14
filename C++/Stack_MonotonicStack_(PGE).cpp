/*
 * Key Pattern: Single-Array Problem (Direct Indexing)
 * - Phase 2: Previous Greater Element (PGE) -> Left-to-Right Traversal
 * - Why Direct Indexing: Standard single-array evaluation. We map exactly to the 
 *   index we are currently processing.
 * - Core Logic: Loop forwards (0 to n-1) to look at the "past". Pop elements that 
 *   are smaller or equal, as they are blocked by the current taller element.
 */

class Solution {
public:
    vector<int> previousGreaterElements(vector<int>& nums) 
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        vector<int> answers(nums.size(), -1);
        stack<int> myStack;

        for(int i = 0; i < nums.size(); i++)
        {
            while(!myStack.empty() && nums[i] >= myStack.top())
            {
                myStack.pop();
            }

            if(myStack.empty() == true)
            {
                myStack.push(nums[i]);
                continue;
            }
            
            answers[i] = myStack.top();
            myStack.push(nums[i]);
        }  

        return answers;
    }
};