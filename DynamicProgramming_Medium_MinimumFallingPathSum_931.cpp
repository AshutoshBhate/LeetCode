//Memoization :

class Solution {
    public:
    
        long helper(int m, int n, vector<vector<int>>& matrix, vector<vector<long>>& dp)
        {
            if(m < 0 || n < 0 || n >= matrix[0].size() || m >= matrix.size())
            {
                return INT_MAX;
            }
            if(m == 0)
            {
                return matrix[0][n];
            }
            if(dp[m][n] != -1)
            {
                return dp[m][n];
            }
    
            long up = matrix[m][n] + helper(m - 1, n, matrix, dp);
            long up_left = matrix[m][n] + helper(m - 1, n - 1, matrix, dp);
            long up_right = matrix[m][n] + helper(m - 1, n + 1, matrix, dp);
    
            dp[m][n] =  min(up, min(up_left, up_right));
            return dp[m][n];
        }
    
        int minFallingPathSum(vector<vector<int>>& matrix)
        {
            int m = matrix.size();
            int n = matrix[0].size();
    
            vector<vector<long>> dp(m, vector<long>(n, -1));
    
            long min_recursion = INT_MAX;
    
            for(int i = 1; i <= n; i++)
            {
                min_recursion = min(min_recursion, helper(m - 1, n - i, matrix, dp));
            }
    
            return min_recursion;
        }
};

//TC: O(M*N)
//SC: O(M*N) + O(N)

//Tabulation : 

class Solution {
    public:
    
        int minFallingPathSum(vector<vector<int>>& matrix)
        {
            int m = matrix.size();
            int n = matrix[0].size();
    
            vector<vector<long>> dp(m, vector<long>(n, 0));
    
            for(int i = 0; i < n; i++)
            {
                dp[0][i] = matrix[0][i];
            }
    
            for(int i = 1; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    long down_left = INT_MAX, down_right = INT_MAX;
    
                    long down = matrix[i][j] + dp[i - 1][j];
    
                    if(j > 0)
                    {   
                        down_left = matrix[i][j] + dp[i - 1][j - 1];
                    }
                    if(j + 1 < m)
                    {
                        down_right = matrix[i][j] + dp[i - 1][j + 1];
                    }
                    
                    dp[i][j] = min(down, min(down_left, down_right));
                }
            }
    
            long min_value = INT_MAX;
    
            for(int i = 1; i <= n; i++)
            {
                min_value = min(min_value, dp[m - 1][n - i]);
            }
    
            return min_value;
        }
};

//TC: O(M*N)
//SC: O(M*N)

//Space Optimized : 

class Solution {
    public:
    
        int minFallingPathSum(vector<vector<int>>& matrix)
        {
            int m = matrix.size();
            int n = matrix[0].size();
    
            vector<long> front(n, 0);
            vector<long> back(n, 0);
    
            for(int i = 0; i < n; i++)
            {
                back[i] = matrix[0][i];
            }
    
            for(int i = 1; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    long down_left = INT_MAX, down_right = INT_MAX;
    
                    long down = matrix[i][j] + back[j];
    
                    if(j > 0)
                    {   
                        down_left = matrix[i][j] + back[j - 1];
                    }
                    if(j + 1 < m)
                    {
                        down_right = matrix[i][j] + back[j + 1];
                    }
                    
                    front[j] = min(down, min(down_left, down_right));
                }
    
                back = front;
            }
    
            long min_value = INT_MAX;
    
            for(int i = 1; i <= n; i++)
            {
                min_value = min(min_value, back[n - i]);
            }
    
            return min_value;
        }
};

//TC: O(M*N)
//SC: O(1)