/*
 * Key Pattern: Single-Array Problem (Direct Indexing)
 * - Phase 1: Next Smaller Element (NSE) -> Right-to-Left Traversal
 * - Why Direct Indexing: We are evaluating and outputting results for a single array. 
 *   Storing results directly into answers[i] is the UNIVERSAL STANDARD.
 * - Note: This is faster, uses less memory, and perfectly handles duplicate numbers 
 *   because it relies on fixed indices, not values.
 */

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        vector<int> answers(prices.size(), 0);
        stack<int> myStack;

        for(int i = prices.size() - 1; i >= 0; i--)
        {
            while(!myStack.empty() && prices[i] < myStack.top())
            {
                myStack.pop();
            }

            if(myStack.empty() == true)
            {
                myStack.push(prices[i]);
                answers[i] = prices[i];
                continue;
            }
            
            answers[i] = prices[i] - myStack.top();
            myStack.push(prices[i]);
        }  

        return answers;
    }
};