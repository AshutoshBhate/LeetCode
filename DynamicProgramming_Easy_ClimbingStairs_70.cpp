class Solution {
    public:
    
        int helper(int n, vector<int>& dp)
        {
            if(n == 0)
            {
                return 1;
            }
            if(n == 1)
            {
                return 1;
            }
    
            if(dp[n] != -1)
            {
              return dp[n];
            }
    
            int left = helper(n - 1, dp);
            int right = helper(n - 2, dp);
    
            dp[n] = left + right;
    
            return dp[n];
        }
    
        int climbStairs(int n)
        {
            cin.tie(nullptr);
            cout.tie(nullptr);
            ios :: sync_with_stdio(false);
    
            vector<int> dp(n + 1, -1);
    
            return helper(n, dp);   
        }
    };