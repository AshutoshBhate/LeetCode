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
    
            int up = helper(m - 1, n, dp);
            int left = helper(m, n - 1, dp);
    
            dp[m][n] = up + left;
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

//To remove the recursion stack space
//In tabulation, first whatever is the base case in recursion, write that
//Also declare a dp array of size m and n

//Express whatever you can in dp. For eg. dp[0][0] = 1

//In tabulation, you start from the base case

class Solution {
    public:
    
        int uniquePaths(int m, int n)
        {
            vector<vector<long long>> dp(m, vector<long long>(n, 0));
    
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    long long up = 0;
                    long long left = 0;
    
                    if(i == 0 && j == 0)
                    {
                        dp[0][0] = 1;
                    }
                    else
                    {
                        if(i > 0)
                        {
                            up = dp[i - 1][j];
                        }
                        if(j > 0)
                        {
                            left = dp[i][j - 1];
                        }
    
                        dp[i][j] = up + left;
                    }
                }
            }
    
            return dp[m - 1][n - 1];
        }
};

//TC: O(N*M)
//SC: O(N*M)

//Space Optimisation :

class Solution {
    public:
        int uniquePaths(int m, int n)
        {
            vector<long long> prev(n, 0);
    
            for(int i = 0; i < m; i++)
            {
                vector<long long> curr(n, 0);
                for(int j = 0; j < n; j++)
                {
                    if(i == 0 && j == 0)
                    {
                        curr[j] = 1;
                    }
                    else
                    {
                        long long up = 0;
                        long long left = 0;
    
                        if(i > 0)
                        {
                            up = prev[j];
                        }
                        if(j > 0)
                        {
                            left = curr[j - 1];
                        }
    
                        curr[j] = up + left;
                    }
                }
    
                prev = curr;
            }
    
            return prev[n - 1];
        }
};

//TC: O(N*M)
//SC: O(N)






