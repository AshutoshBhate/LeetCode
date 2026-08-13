/*
 * Key Pattern: Single-Array Problem (Direct Indexing) & Subarray Bounds
 * - Phase: Combined Previous Smaller Element (PSE) & Next Smaller Element (NSE)
 * - Why Indices: We need the distance between the current element and its bounds 
 *   to calculate how many subarrays it dominates as the minimum. 
 * - Note on Duplicates: To avoid double-counting subarrays with duplicate minimums 
 *   (e.g., [2, 2]), we pop ">=" for PSE (finding strictly smaller) and ">" for NSE 
 *   (finding smaller or equal).
 */

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int n = arr.size();
        long long MOD = 1e9 + 7;
        
        vector<int> pse(n, -1);
        vector<int> nse(n, n); 
        
        stack<int> myStack;

        for(int i = 0; i < n; i++)
        {
            while(!myStack.empty() && arr[myStack.top()] >= arr[i])
            {
                myStack.pop();
            }

            if(!myStack.empty())
            {
                pse[i] = myStack.top();
            }
            myStack.push(i);
        }

        while(!myStack.empty())
        {
            myStack.pop();
        }

        for(int i = n - 1; i >= 0; i--)
        {
            while(!myStack.empty() && arr[myStack.top()] > arr[i])
            {
                myStack.pop();
            }

            if(!myStack.empty())
            {
                nse[i] = myStack.top();
            }
            myStack.push(i);
        }

        long long total_sum = 0;

        for(int i = 0; i < n; i++)
        {
            long long left_count = i - pse[i];
            long long right_count = nse[i] - i;
            
            long long subarrays = (left_count * right_count) % MOD;
            long long contribution = (subarrays * arr[i]) % MOD;
            
            total_sum = (total_sum + contribution) % MOD;
        }

        return total_sum;
    }
};