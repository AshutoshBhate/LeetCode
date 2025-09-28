//Memoization : 

class Solution {
public:

    long helper(int m, int n, vector<vector<int>>& grid, vector<vector<long>>& dp)
    {
        if(m == 0 && n == 0)
        {
            return grid[0][0];
        }
        if(m < 0 || n < 0)
        {
            return INT_MAX;
        }

        if(dp[m][n] != -1)
        {
            return dp[m][n];
        }

        long up = grid[m][n] + helper(m - 1, n, grid, dp);
        long left = grid[m][n] + helper(m, n - 1, grid, dp);

        dp[m][n] =  min(up, left);
        return dp[m][n];
    }

    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long>> dp(m, vector<long>(n, -1));

        return static_cast<int>(helper(m - 1, n - 1, grid, dp));    
    }
};

//TC: O(N*M)
//SC: O(N*M) + O((m - 1) + (n - 1))

//Tabulation : 

class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid)
        {
            int m = grid.size();
            int n = grid[0].size();
    
            vector<vector<int>> dp(m, vector<int>(n, 0));
    
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    long up = INT_MAX, left = INT_MAX;
    
                    if(i == 0 && j == 0)
                    {
                        dp[i][j] = grid[0][0];
                    }
                    else
                    {
                        if(i > 0)
                        {
                            up = grid[i][j] + dp[i - 1][j];
                        }
                        if(j > 0)
                        {
                            left = grid[i][j] + dp[i][j - 1];
                        }
    
                        dp[i][j] = min(up, left);
                    }
                }
            }
    
            return dp[m - 1][n - 1];
        }
};

//Space Optimization : 

class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid)
        {
            int m = grid.size();
            int n = grid[0].size();
    
            vector<int> prev(n, 0);
    
            for(int i = 0; i < m; i++)
            {
                vector<int> curr(n, 0);
    
                for(int j = 0; j < n; j++)
                {
                    long up = INT_MAX, left = INT_MAX;
    
                    if(i == 0 && j == 0)
                    {
                        curr[j] = grid[0][0];
                    }
                    else
                    {
                        if(i > 0)
                        {
                            up = grid[i][j] + prev[j];
                        }
                        if(j > 0)
                        {
                            left = grid[i][j] + curr[j - 1];
                        }
    
                        curr[j] = min(up, left);
                    }
                }
                prev = curr;
            }
    
            return prev[n - 1];
        }
};