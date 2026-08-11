/*
[NGE] (Already completed)
  │
  ▼
Phase 1: Next Smaller Element (NSE) (Doing it in this code)  ──► Keeps direction (right), flips operator
  │
  ▼
Phase 2: Previous Greater Element (PGE)  ──► Keeps condition (greater), flips direction (left)
  │
  ▼
Phase 3: Previous Smaller Element (PSE)  ──► Flips both (left + smaller)
  │
  ▼
Phase 4: Combined Bounds (NSE + PSE)  ──► The interview standard (Histogram & Subarrays)
*/

/*
 * Key Pattern: Direct Index-based Result Assignment
 * - Constraint: Elements CAN REPEAT (duplicates allowed).
 * - Why Direct Indexing: Since we output results for the same array in 1-to-1 order,
 *   we store results directly into answers[i].
 * - Note: Direct index assignment bypasses hash map key collisions when numbers repeat.
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