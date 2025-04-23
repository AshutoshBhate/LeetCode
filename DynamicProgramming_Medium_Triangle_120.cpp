//Memoization : 

class Solution {
public:

    int helper(int m, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        if(m == triangle.size() - 1)
        {
            return triangle[m][n];
        }
        if(m > triangle.size() - 1)
        {
            return INT_MAX;
        }
        if(n > triangle[m].size() - 1)
        {
            return INT_MAX;
        }
        if(dp[m][n] != -1)
        {
            return dp[m][n];
        }

        int left = triangle[m][n] + helper(m + 1, n, triangle, dp);
        int right = triangle[m][n] + helper(m + 1, n + 1, triangle, dp);

        dp[m][n] = min(left,right);

        return dp[m][n];
    }

    int minimumTotal(vector<vector<int>>& triangle)
    {
        int m = 0;
        int n = 0;

        vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size() - 1].size(), -1));

        return helper(m, n, triangle, dp);
    }
};

//TC: O(M*N)
//SC: O(N) + O(M*N)

//Tabulation : 
//In memoization, we have gone from 0 -> n - 1, thus, in tabtulation we go reverse that is from (n - 1) -> 0

class Solution {
    public:
    
        int minimumTotal(vector<vector<int>>& triangle)
        {
            int m = triangle.size();
            int n = triangle[triangle.size() - 1].size();
    
            vector<vector<int>> dp(m, vector<int>(n, -1));
            for(int j = 0; j < n; j++)
            {
                dp[m - 1][j] = triangle[m - 1][j];
            }
            for(int i = m - 2; i >= 0; i--)
            {
                for(int j = i; j >= 0; j--)
                {
                    long left = INT_MAX, right = INT_MAX;
                    
                    left = triangle[i][j] + dp[i + 1][j];
                    right = triangle[i][j] + dp[i + 1][j + 1];
    
                    dp[i][j] = min(left, right);
                }
            }
    
            return dp[0][0];
        }
};

//TC: O(M*N)
//SC: O(M*N)