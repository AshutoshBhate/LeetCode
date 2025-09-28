//Memoization : 

class Solution {
public:

    int helper(int index_1, int index_2, string s, string reverse_s, vector<vector<int>>& dp)
    {
        if(index_1 < 0 || index_2 < 0)
        {
            return 0;
        }

        if(dp[index_1][index_2] != -1)
        {
            return dp[index_1][index_2];
        }

        if(s[index_1] == reverse_s[index_2])
        {
            return 1 + helper(index_1 - 1, index_2 - 1, s, reverse_s, dp);
        }

        dp[index_1][index_2] =  0 + max(helper(index_1, index_2 - 1, s, reverse_s, dp), helper(index_1 - 1, index_2, s, reverse_s, dp));

        return dp[index_1][index_2];
    }

    int longestPalindromeSubseq(string s)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        string reverse_s = "";

        for(int i = s.size() - 1; i >= 0; i--)
        {
            reverse_s += s[i];
        }

        int m = s.size();
        int n = reverse_s.size();

        vector<vector<int>> dp(m, vector<int>(n, - 1));

        return helper(m - 1, n - 1, s, reverse_s, dp);
    }
};

//Tabulation : 

class Solution {
public:

    int longestPalindromeSubseq(string s)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        string reverse_s = "";

        for(int i = s.size() - 1; i >= 0; i--)
        {
            reverse_s += s[i];
        }

        int m = s.size();
        int n = reverse_s.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

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
                if(s[i - 1] == reverse_s[j - 1])
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

//Space Optimization :

class Solution {
public:

    int longestPalindromeSubseq(string s)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        string reverse_s = "";

        for(int i = s.size() - 1; i >= 0; i--)
        {
            reverse_s += s[i];
        }

        int m = s.size();
        int n = reverse_s.size();

        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for(int i = 0; i <= n; ++)
        {
            prev[i] = 0;
        }

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s[i - 1] == reverse_s[j - 1])
                {
                    curr[j] =  1 + prev[j - 1];
                }
                else
                {
                    curr[j] = 0 + max(prev[j], curr[j - 1]);
                }
            }

            prev = curr;
        }

        return prev[n];
    }
};