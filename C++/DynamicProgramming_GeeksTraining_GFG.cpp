//Memoization:

class Solution {
  public:
    int helper(int day, int last, vector<vector<int>>& arr, vector<vector<int>>& dp)
    {
        if(dp[day][last] != -1)
        {
            return dp[day][last];
        }
        
        if(day == 0)
        {
            int maxi = 0;
            for(int task = 0; task < 3; task++)
            {
                if(task != last)
                {
                    maxi = max(maxi, arr[0][task]);
                }
            }
            
            return maxi;
        }
        
        int maxi = 0;
        for(int task = 0; task < 3; task++)
        {
            if(task != last)
            {
                int point = arr[day][task] + helper(day - 1, task, arr, dp);
                maxi = max(maxi, point);
            }
        }
        
        dp[day][last] = maxi;
        
        return maxi;
    }
  
    int maximumPoints(vector<vector<int>>& arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        
        return helper(n - 1, 3, arr, dp);
    }
};

//TC : O(N*4)*3
//SC : O(N) + O(N*4)

//Tabulation:

//Declare the similar size dp array

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr)
    {
        int n = arr.size();
      
        vector<vector<int>> dp(n, vector<int>(4, 0));
      
        dp[0][0] = max(arr[0][1], arr[0][2]);   //Note that the [][0] in dp is the previous task denatation
        dp[0][1] = max(arr[0][0], arr[0][2]);   //similar to the last of the memoization function call
        dp[0][2] = max(arr[0][0], arr[0][1]);
      
        for(int day = 1; day < n; day++)
        {   
            for(int last = 0; last < 4; last++)
            {
                for(int task = 0; task < 3; task++)
                {
                    if(task != last)
                    {
                        int point = arr[day][task] + dp[day - 1][task];
                        dp[day][last] = max(dp[day][last], point);
                    }
                }
            }
        }
        int last_max = 0;
        for(int i = 0; i < 4; i++)
        {
            last_max = max(last_max, dp[n-1][i]);
        }

        return last_max;
    }
};

//TC : O(N*4*3)
//SC : O(N*4)

//Space Optimisation:

class Solution {
  public:
        int maximumPoints(vector<vector<int>>& arr)
        {
            int n = arr.size();
            vector<int> prev(4, 0);
        
            prev[0] = max(arr[0][1], arr[0][2]);
            prev[1] = max(arr[0][0], arr[0][2]);
            prev[2] = max(arr[0][0], arr[0][1]);
        
            for(int day = 1; day < n; day++)
            {
                vector<int> temp(4, 0);
                for(int last = 0; last < 4; last++)
                {
                    temp[last] = 0;
                
                    for(int task = 0; task < 3; task++)
                    {
                        if(task != last)
                        {
                        temp[last] = max(temp[last], arr[day][task] + prev[task]);
                        }
                    }
                }
                prev = temp;
            }
        
            int final_max = 0;
        
            for(int i = 0; i < 4; i++)
            {
            final_max = max(final_max,prev[i]);
            }
        
            return final_max;
        }
};

//TC : O(N*4*3)
//SC : O(4)

