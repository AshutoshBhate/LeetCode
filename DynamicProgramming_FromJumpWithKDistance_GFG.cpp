//Memoization:

class Solution {
    public:
        int helper(int ind, vector<int>& height, vector<int>& dp, int k)
        {
            if (ind == 0)
            {
                return 0;
            }
            if (dp[ind] != -1)
            {
                return dp[ind];
            }
            
            int Steps = INT_MAX;
            
            for (int j = 1; j <= k; j++)
            {
                if (ind - j >= 0)
                {
                    int jump = helper(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
                    Steps = min(Steps, jump);
                }
            }
            
            return dp[ind] = Steps;
        }
        
        int minimizeCost(int k, vector<int>& arr)
        {
            int n = arr.size();
            vector<int> dp(n, -1);  
            return helper(n - 1, arr, dp, k);
        }
};

//Tabulation:

class Solution {
    public:
        int minimizeCost(int k, vector<int>& height)
        {
            int n = height.size();
            vector<int> dp(n, INT_MAX);

            dp[0] = 0;
            
            for (int i = 1; i < n; i++)
            {
                for (int j = 1; j <= k; j++)
                {
                    if (i - j >= 0)
                    {
                        int jump = dp[i - j] + abs(height[i] - height[i - j]);
                        dp[i] = min(dp[i], jump);
                    }
                }
            }
            
            return dp[n - 1];
        }
};

