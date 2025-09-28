//Memoization : 

//Style A : Cannot be mapped to Tabulation directly:

//As we are going from 0 to n - 1, the additional base cases aren't needed (The 0th element might be 0 so we have to return 2 choices, etc.)

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

//Here as we are coming from n - 1 to 0, we need additional checks for checking whether the 0th element might have 0 so we need to return 2

class Solution {
  public:
  
    int helper(int index, int sum, vector<int>& arr, vector<vector<int>>& dp)
    {
        if(index == 0)
        {
            if(sum == 0 && arr[0] == 0)
            {
                return 2;
            }
            if(sum == 0 || sum == arr[0])
            {
                return 1;
            }
            return 0;
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
            dp[0][0] = 2; // Pick or Not Pick, this condition is needed only when in the constraints, it is written that numbers will be starting from 0 and not 1
        }
        else
        {
            dp[0][0] = 1; // only Not Pick
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
