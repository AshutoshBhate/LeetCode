//Memoization : 

//Style A : Cannot be mapped to Tabulation directly:

class Solution {
  public:
  
    int helper(int index, vector<int>& arr, int target, int sum, vector<vector<int>>& dp)
    {
        if(target == sum && index == arr.size())
        {
            return 1;
        }
        if(index == arr.size())
        {
            return 0;
        }
        
        if (sum > target)
        {
            return 0;
        }
        
        if(dp[index][sum] != -1)
        {
            return dp[index][sum];
        }
        
        //Pick
        int Pick = helper(index + 1, arr, target, sum + arr[index], dp);
        
        //Not Pick
        int notPick = helper(index + 1, arr, target, sum, dp);
        
        return dp[index][sum] = Pick + notPick;
        
    }
  
    int perfectSum(vector<int>& arr, int target)
    {
        int n = arr.size();
        int count = 0, sum = 0;
        
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        
        return helper(0, arr, target, sum, dp);
    }
};

//Style B : Can be mapped to Tabulation directly: 

class Solution {
  public:
  
    int helper(int index, int sum, vector<int>& arr, vector<vector<int>>& dp)
    {
        if(sum == 0)
        {
            return 1;
        }
        
        if(index == 0)
        {
            return arr[0] == sum ? 1 : 0;
        }
        
        if(dp[index][sum] != -1)
        {
            return dp[index][sum];
        }
        
        //Not Pick
        int notPick = helper(index - 1, sum, arr, dp);
        
        //Pick
        int pick = 0;
        if(arr[index] <= sum)
        {
            pick = helper(index - 1, sum - arr[index], arr, dp);
        }
        
        return dp[index][sum] = pick + notPick;
    }
  
    int perfectSum(vector<int>& arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        
        return helper(n - 1, target, arr, dp);
    }
};

//Tabulation : 

class Solution {
  public:
  
    int perfectSum(vector<int>& arr, int target)
    {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        if(arr[0] == 0)
        {
            dp[0][0] = 2; // pick or not pick
        }
        else
        {
            dp[0][0] = 1; // only not pick
            if(arr[0] <= target)
            {
                dp[0][arr[0]] = 1; // pick
            }
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= target; j++)
            {
                //Not Pick
                int notPick = dp[i - 1][j];
        
                //Pick
                int pick = 0;
                if(arr[i] <= j)
                {
                    pick = dp[i - 1][j - arr[i]];
                }
        
                dp[i][j] = pick + notPick;
            }
        }
        
        return dp[n - 1][target];
    }
};

//Space Optimization : 

class Solution {
  public:
  
    int perfectSum(vector<int>& arr, int target)
    {
        int n = arr.size();

        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);

        if(arr[0] == 0)
        {
            prev[0] = 2; // pick or not pick
        }
        else
        {
            prev[0] = 1; // only not pick
            if(arr[0] <= target)
            {
                prev[arr[0]] = 1; // pick
            }
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= target; j++)
            {
                //Not Pick
                int notPick = prev[j];
        
                //Pick
                int pick = 0;
                if(arr[i] <= j)
                {
                    pick = prev[j - arr[i]];
                }
        
                curr[j] = pick + notPick;
            }
            
            prev = curr;
        }
        
        return prev[target];
    }
};
