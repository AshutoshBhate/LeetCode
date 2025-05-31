//Memoization : 

class Solution {
  public:
  
    int helper(int index, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp)
    {
        if(index == 0)
        {
            if(wt[index] <= W)
            {
                return val[index];
            }
            else
            {
                return 0;
            }
        }
        
        if(dp[index][W] != -1)
        {
            return dp[index][W];
        }
        
        int Take = INT_MIN;
        
        int notTake = helper(index - 1, W, val, wt, dp);
        
        if(wt[index] <= W)
        {
            Take = val[index] + helper(index - 1, W - wt[index], val, wt, dp);
        }
        
        dp[index][W] = max(notTake, Take);
        return dp[index][W];
        
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = wt.size();
        
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        
        return helper(n - 1, W, val, wt, dp);
    }
};