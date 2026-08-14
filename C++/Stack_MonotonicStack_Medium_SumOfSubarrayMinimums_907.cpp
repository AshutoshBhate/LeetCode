/*
 * Problem: Sum of Subarray Minimums (LeetCode 907)
 * Pattern: Monotonic Stack with Subarray Bounds
 *
 * Key Concepts:
 * 1. Index-Based Stack: We push array indices (i) to calculate distance 
 *    spans: left_count = i - pse[i] and right_count = nse[i] - i.
 * 2. Virtual Boundaries:
 *    - Default PSE = -1 (extends reach to the left boundary).
 *    - Default NSE =  n (extends reach to the right boundary).
 * 3. Asymmetric Bounds for Duplicates:
 *    - PSE finds Previous STRICTLY Smaller Element (<) by popping stack top >= arr[i].
 *    - NSE finds Next Smaller OR EQUAL Element (<=) by popping stack top > arr[i].
 *    - This asymmetry breaks ties for duplicate values (e.g., [2, 2]) and 
 *      prevents double-counting subarrays.
 */

class Solution {
public:

    vector<int> findNSE(int n, vector<int>& arr)
    {
        stack<int> myStack;
        vector<int> answer(n, n);

        for(int i = n - 1; i >= 0; i--)
        {
            while(!myStack.empty() && arr[i] < arr[myStack.top()])
            {
                myStack.pop();
            }

            if(myStack.empty())
            {
                myStack.push(i);
                continue;
            }
            answer[i] = myStack.top();
            myStack.push(i);
        }

        return answer;
    }

    vector<int> findPSE(int n, vector<int>& arr)
    {
        stack<int> myStack;
        vector<int> answer(n, -1);

        for(int i = 0; i < n; i++)
        {
            while(!myStack.empty() && arr[i] <= arr[myStack.top()])
            {
                myStack.pop();
            }

            if(myStack.empty())
            {
                myStack.push(i);
                continue;
            }
            answer[i] = myStack.top();
            myStack.push(i);
        }

        return answer;
    }

    int sumSubarrayMins(vector<int>& arr) 
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int n = arr.size();
        long long MOD = 1e9 + 7;
        
        vector<int> pse = findPSE(n, arr);
        vector<int> nse = findNSE(n, arr); 

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