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

//Tabulation : 

class Solution {
  public:
  
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = wt.size();
        
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        for(int i = 0; i <= W; i++)
        {
            dp[0][i] = wt[0] <= i ? val[0] : 0;
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= W; j++)
            {
                int Take = INT_MIN;
        
                int notTake = dp[i - 1][j];

                if(wt[i] <= j)
                {
                    Take = val[i] + dp[i - 1][j - wt[i]];
                }

                dp[i][j] = max(notTake, Take);
            }
        }
        
        return dp[n - 1][W];
    }
};

//Space Optimization :

class Solution {
  public:
  
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = wt.size();
        
        vector<int> curr(W + 1, 0);
        vector<int> prev(W + 1, 0);

        for(int i = 0; i <= W; i++)
        {
            prev[i] = wt[0] <= i ? val[0] : 0;
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= W; j++)
            {
                int Take = INT_MIN;
        
                int notTake = prev[j];

                if(wt[i] <= j)
                {
                    Take = val[i] + prev[j - wt[i]];
                }

                curr[j] = max(notTake, Take);
            }

            prev = curr;
        }
        
        return prev[W];
    }
};