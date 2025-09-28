//Memoization : 

class Solution {
  public:
  
    int helper(int index, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp)
    {
        if(index == 0)
        {
            if(wt[index] <= W)
            {
                int sum = 0;
                
                for(int i = 0; i < (W / wt[index]); i++)
                {
                    sum += val[index];
                }
                
                return sum;
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
            Take = val[index] + helper(index, W - wt[index], val, wt, dp);
        }
        
        dp[index][W] = max(notTake, Take);
        
        return dp[index][W];
        
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity)
    {
        int n = wt.size();
        
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        
        return helper(n - 1, capacity, val, wt, dp);
    }
};

//Tabulation : 

class Solution {
  public:
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity)
    {
        int n = wt.size();
        
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

        for(int i = 0; i <= capacity; i++)
        {
            if(wt[0] <= i)
            {
                int sum = 0;
                
                for(int j = 0; j < (i / wt[0]); j++)
                {
                    sum += val[0];
                }
                
                dp[0][i] = sum;
            } 
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= capacity; j++)
            {
                int Take = INT_MIN;
        
                int notTake = dp[i - 1][j];

                if(wt[i] <= j)
                {
                    Take = val[i] + dp[i][j - wt[i]];
                }

                dp[i][j] = max(notTake, Take);
            }
        }
        
        return dp[n - 1][capacity];
    }
};

//Space Optimization : 

class Solution {
  public:
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity)
    {
        int n = wt.size();
        
        vector<int> curr(capacity + 1, 0);
        vector<int> prev(capacity + 1, 0);

        for(int i = 0; i <= capacity; i++)
        {
            if(wt[0] <= i)
            {
                int sum = 0;
                
                for(int j = 0; j < (i / wt[0]); j++)
                {
                    sum += val[0];
                }
                
                prev[i] = sum;
            } 
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= capacity; j++)
            {
                int Take = INT_MIN;
        
                int notTake = prev[j];

                if(wt[i] <= j)
                {
                    Take = val[i] + curr[j - wt[i]];
                }

                curr[j] = max(notTake, Take);
            }

            prev = curr;
        }
        
        return prev[capacity];
    }
};