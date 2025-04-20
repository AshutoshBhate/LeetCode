//Memoization : 

class Solution {
    public:
    
        int helper(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
        {
            if(m == 0 && n == 0)
            {
                return 1;
            }
            if(m < 0 || n < 0 || obstacleGrid[m][n] == 1)
            {
                return 0;
            }
    
            if(dp[m][n] != -1)
            {
                return dp[m][n];
            }
    
            int up = helper(m - 1, n, obstacleGrid, dp);
            int left = helper(m, n - 1, obstacleGrid, dp);
    
            dp[m][n] = up + left;
            return dp[m][n];
        }
    
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
        {
            if(obstacleGrid[0][0] == 1)
            {
                return 0;
            }
    
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
    
            vector<vector<int>> dp(m, vector<int>(n, -1));
    
            return helper(m - 1, n - 1, obstacleGrid, dp);    
        }
};

//Tabulation : 

class Solution {
    public:
        
        int mod = (int)(1e9 + 7);
    
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
        {
    
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
    
            vector<vector<int>> dp(m, vector<int>(n, 0));
    
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(obstacleGrid[i][j] == 1)
                    {
                        dp[i][j] = 0;
                    }
                    else if(i == 0 && j == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        int up = 0, left = 0;
                        if(i > 0)
                        {
                            up = dp[i - 1][j];
                        }
                        if(j > 0)
                        {
                            left = dp[i][j - 1];
                        }
    
                        dp[i][j] = (up + left)%mod;
                    }
                }
            }
            
            return dp[m - 1][n - 1];
        }
};