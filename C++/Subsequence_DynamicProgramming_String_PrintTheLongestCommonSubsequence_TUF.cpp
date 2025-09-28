//For printing one Longest Common Subsequence: (Not for printing all)

class Solution {
  public:
    string allLCS(string &s1, string &s2)
    {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));   //One extra space for offsetting 

        for(int i = 0; i < n + 1; i++)
        {
            dp[0][i] = 0;
        }

        for(int j = 0; j < m + 1; j++)
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
                }
                else
                {
                    dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        int len = dp[m][n];
        
        string ans = "";
        
        for(int i = 0; i < len; i++)
        {
            ans += '$';
        }
        
        //Backtracking Worst Case TC : O(N + M) 

        int index = len - 1;
        
        int i = m, j = n;
        
        while(i > 0 && j > 0)
        {
            if(s1[i - 1] == s2[j - 1])
            {
                ans[index] = s1[i - 1];
                index--;
                i--;
                j--;
            }
            else if(dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
        
        return ans;
    }
};

//For printing all Longest Common Subsequences:
