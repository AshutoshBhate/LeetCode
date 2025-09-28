//Tabulation : 

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2)
    {
        int m = s1.size();
        int n = s2.size();
        int max_count = 0;
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 0; i <= n; i++)
        {
            dp[0][i] = 0;
        }

        for(int j = 0; j <= m; j++)
        {
            dp[j][0] = 0;
        }

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] =  1 + dp[i - 1][j - 1];
                    max_count = max(max_count, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        
        return max_count;
    }
};

//Space Optimization : 

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2)
    {
        int m = s1.size();
        int n = s2.size();
        int max_count = 0;
        
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        
        for(int i = 0; i <= n; i++)
        {
            prev[i] = 0;
        }

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s1[i - 1] == s2[j - 1])
                {
                    curr[j] =  1 + prev[j - 1];
                    max_count = max(max_count, curr[j]);
                }
                else
                {
                    curr[j] = 0;
                }
            }

            prev = curr;
        }
        
        return max_count;
    }
};

