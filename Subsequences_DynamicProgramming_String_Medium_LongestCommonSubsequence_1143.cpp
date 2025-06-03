//Memoization : 

class Solution {
public:

    int helper(string text1, string text2, int index_1, int index_2, vector<vector<int>>& dp)
    {
        if(index_1 < 0 || index_2 < 0)
        {
            return 0;
        }

        if(dp[index_1][index_2] != -1)
        {
            return dp[index_1][index_2];
        }

        //Match
        if(text1[index_1] == text2[index_2])
        {
            return 1 + helper(text1, text2, index_1 - 1, index_2 - 1, dp);
        }

        //Not Match
        return 0 + max(helper(text1, text2, index_1 - 1, index_2, dp), helper(text1, text2, index_1, index_2 - 1, dp));
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int index_1 = text1.size() - 1;
        int index_2 = text2.size() - 1;

        vector<vector<int>> dp(index_1 + 1, vector<int>(index_2 + 1, -1));

        return helper(text1, text2, index_1, index_2, dp);    
    }
};

//Tabulation : 

class Solution {
public:

    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] =  1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};