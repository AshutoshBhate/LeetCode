//Memoization : 

class Solution {
  public:
  
    bool helper(int index, vector<int>& arr, int target, vector<vector<int>>& dp)
    {
        if(target == 0)
        {
            return true;
        }
        
        if(index == 0)
        {
            return arr[0] == target;
        }
        
        if(index < 0)
        {
            return false;
        }
        
        if(dp[index][target] != -1)
        {
            return dp[index][target];
        }
        
        bool notTake = false;
        bool Take = false;
        
        notTake = helper(index - 1, arr, target, dp);
        
        if(arr[index] <= target)
        {
            Take = helper(index - 1, arr, target - arr[index], dp);
        }
        
        dp[index][target] = notTake || Take;
        return dp[index][target];
    }
  
    bool isSubsetSum(vector<int>& arr, int sum)
    {
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        
        return helper(n - 1, arr, sum, dp);
    }
};

//Tabulation : 

class Solution {
  public:
  
    bool isSubsetSum(vector<int>& arr, int sum)
    {
        int n = arr.size();
        
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));
        
        for(int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        
        dp[0][arr[0]] = true;
        
        for(int i = 1; i < n; i++)
        {
            for(int target = 1; target <= sum; target++)
            {
                bool notTake = dp[i - 1][target];
                
                bool Take = false;
        
                if(arr[i] <= target)
                {
                    Take = dp[i - 1][target - arr[i]];
                }
                
                dp[i][target] = notTake || Take;
            }
        }
        
        return dp[n - 1][sum];
    }
};

//Space Optimization : 

class Solution {
  public:
  
    bool isSubsetSum(vector<int>& arr, int sum)
    {
        int n = arr.size();
        
        vector<bool> prev(sum + 1, 0);
        vector<bool> curr(sum + 1, 0);
        
        
        prev[0] = true;
        curr[0] = true;
        
        prev[arr[0]] = true;
        
        for(int i = 1; i < n; i++)
        {
            for(int target = 1; target <= sum; target++)
            {
                bool notTake = prev[target];
                
                bool Take = false;
        
                if(arr[i] <= target)
                {
                    Take = prev[target - arr[i]];
                }
                
                curr[target] = notTake || Take;
            }
            
            prev = curr;
        }
        
        return prev[sum];
    }
};

//TC: O(N * Target)
//SC: O(Target)