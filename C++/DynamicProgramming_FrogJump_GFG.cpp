class Solution {
    public:
      int helper(vector<int>& height, vector<int>& dp, int n)
      {
        if(n == 0)
        {
            return 0;
        }
        
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        int right = INT_MAX;
        
        if(n >= 2)
        {
            right = helper(height, dp, n - 2) + abs(height[n] - height[n - 2]);
        }
        
        int left = helper(height, dp, n - 1) + abs(height[n] - height[n - 1]);
        
        dp[n] = min(left, right);
        return dp[n];
      }
    
      int minCost(vector<int>& height)
      {
        int n = height.size();
        vector<int> dp(n, -1);
        
        return helper(height, dp, n - 1);   //We take n - 1 as that is the last index
      }
  };