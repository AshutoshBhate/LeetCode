//Memoization:

class Solution {
    public:
        int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k)
        {
            // Base case: If we are at the first stone, no cost is needed.
            if (ind == 0)
            {
                return 0;
            }
                
            // If the result for this index has already been computed, return it.
            if (dp[ind] != -1)
            {
                return dp[ind];
            }
            
            int mmSteps = INT_MAX;
            
            // Try all possible jumps from 1 to k
            for (int j = 1; j <= k; j++)
            {
                if (ind - j >= 0)
                {
                    int jump = solveUtil(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
                    mmSteps = min(mmSteps, jump);
                }
            }
            
            // Store the computed result for this index and return it.
            return dp[ind] = mmSteps;
        }
        
        // Main function to compute the minimal cost to reach the last stone
        int minimizeCost(int k, vector<int>& arr)
        {
            int n = arr.size();
            vector<int> dp(n, -1);  // Initialize memoization array
            return solveUtil(n - 1, arr, dp, k); // Start the recursion from the last index
        }
};

//Tabulation:

class Solution {
    public:
        int minimizeCost(int k, vector<int>& height)
        {
            int n = height.size();
            vector<int> dp(n, INT_MAX);

            dp[0] = 0;  // Base case: cost to reach the first stone is 0
            
            for (int i = 1; i < n; i++)
            {
                for (int j = 1; j <= k; j++)
                {
                    if (i - j >= 0)
                    {
                        int jump = dp[i - j] + abs(height[i] - height[i - j]);
                        dp[i] = min(dp[i], jump);
                    }
                }
            }
            
            return dp[n - 1];  // Minimum cost to reach the last stone
        }
};
    