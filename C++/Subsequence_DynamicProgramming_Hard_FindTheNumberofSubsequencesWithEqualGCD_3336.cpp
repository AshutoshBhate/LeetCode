class Solution {
public:
    int subsequencePairCount(vector<int>& nums) 
    {
        int n = nums.size();
        int maxVal = 0;
        for (int x : nums) 
        {
            maxVal = max(maxVal, x);
        }

        int MOD = 1e9 + 7;

        vector<vector<int>> dp(maxVal + 1, vector<int>(maxVal + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) 
        {
            vector<vector<int>> nextDp = dp;

            for (int g1 = 0; g1 <= maxVal; g1++) 
            {
                for (int g2 = 0; g2 <= maxVal; g2++) 
                {
                    if (dp[g1][g2] == 0) continue;

                    int nextG1 = (g1 == 0) ? x : gcd(g1, x);
                    nextDp[nextG1][g2] = (nextDp[nextG1][g2] + dp[g1][g2]) % MOD;

                    int nextG2 = (g2 == 0) ? x : gcd(g2, x);
                    nextDp[g1][nextG2] = (nextDp[g1][nextG2] + dp[g1][g2]) % MOD;
                }
            }

            dp = move(nextDp);
        }

        long long totalPairs = 0;
        for (int g = 1; g <= maxVal; g++) 
        {
            totalPairs = (totalPairs + dp[g][g]) % MOD;
        }

        return totalPairs;
    }
};
