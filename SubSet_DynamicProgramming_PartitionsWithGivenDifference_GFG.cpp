//S1 - S2 = D
//S1 = TotalSum - S2
//TotalSum - S2 - S2 = D
//S2 = (TotalSum - D) / 2
//Hence we have to find subsets with this sum. That is the answer!

//Memoization : 

class Solution {
  public:

    int mod = (int)(1e9 + 7);
  
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
        
        return dp[index][sum] = pick + notPick % mod;
    }


    int countPartitions(vector<int>& arr, int d)
    {
        int n = arr.size();
        
        int totSum = 0;

        for(auto it : arr)
        {
            totSum += it;
        }

        if(totSum - d < 0 || (totSum - d) % 2)
        {
            return false;
        }

        vector<vector<int>> dp(n, vector<int>(((totSum - d) / 2) + 1, -1));

        return helper(n - 1, (totSum - d) / 2, arr, dp); 
    }
};

//Tabulation : 

class Solution {
  public:

    int mod = (int)(1e9 + 7);
  
    int countPartitions(vector<int>& arr, int d)
    {
        
        int n = arr.size();
        
        int totSum = 0;

        for(auto it : arr)
        {
            totSum += it;
        }

        if(totSum - d < 0 || (totSum - d) % 2)
        {
            return 0;
        }
        
        int target = (totSum - d) / 2;

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
        
                dp[i][j] = (pick + notPick) % mod; 
            }
        }
        
        return dp[n - 1][target];
    }
};

//Space Optimization :

class Solution {
  public:

    int mod = (int)(1e9 + 7);
  
    int countPartitions(vector<int>& arr, int d)
    {
        
        int n = arr.size();
        
        int totSum = 0;

        for(auto it : arr)
        {
            totSum += it;
        }

        if(totSum - d < 0 || (totSum - d) % 2)
        {
            return 0;
        }
        
        int target = (totSum - d) / 2;

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