//Memoization : 

class Solution {
    public:
        int helper(int m, int n, vector<vector<int>>& dp)
        {  
            if(m == 0 && n == 0)
            {
                return 1;
            }
            if(m < 0 || n < 0)
            {
                return 0;
            }
    
            if(dp[m][n] != -1)
            {
                return dp[m][n];
            }    
    
            int down = helper(m - 1, n, dp);
            int right = helper(m, n - 1, dp);
    
            dp[m][n] = down + right;
            return dp[m][n];
        }
    
        int uniquePaths(int m, int n)
        {
            vector<vector<int>>dp(m, vector<int>(n, -1));
    
            return helper(m - 1, n - 1, dp);
        }
};

//TC: O(N*M)
//SC: O((n - 1) + (m - 1)) + O(N * M)
//          Path Length     For DP array

//Tabulation : 

// To remove the recurssion stack space



