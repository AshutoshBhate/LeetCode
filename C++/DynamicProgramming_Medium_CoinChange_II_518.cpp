//Memoization : 

class Solution {
public:

    int helper(int index, int amount, vector<int>& coins, vector<vector<unsigned int>>& dp)
    {
        if(index == 0)
        {
            return amount % coins[index] == 0;
        }

        if(dp[index][amount] != -1)
        {
            return dp[index][amount];
        }

        unsigned int Take = 0, notTake = 0;

        notTake = helper(index - 1, amount, coins, dp);

        if(coins[index] <= amount)
        {
            Take = helper(index, amount - coins[index], coins, dp);
        }

        dp[index][amount] = Take + notTake;
        return dp[index][amount];
    }

    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();

        vector<vector<unsigned int>> dp(n, vector<unsigned int>(amount + 1, -1));

        return helper(n - 1, amount, coins, dp);    
    }
};

//Tabulation : 

class Solution {
public:

    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();

        vector<vector<unsigned int>> dp(n, vector<unsigned int>(amount + 1, 0));
        
        for(int i = 0; i <= amount; i++)
        {
            if(i % coins[0] == 0)
            {
                dp[0][i] = 1;
            }
            else
            {
                dp[0][i] = 0;
            }
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= amount; j++)
            {
                unsigned int Take = 0;
                unsigned int notTake = dp[i - 1][j];

                if(coins[i] <= j)
                {
                    Take = dp[i][j - coins[i]];
                }
            
                dp[i][j] = Take + notTake;
            }
        }

        return dp[n - 1][amount];
    }
};

//Space Optimization : 

class Solution {
public:

    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();

        vector<unsigned int> prev(amount + 1, 0);
        vector<unsigned int> curr(amount + 1, 0);
        
        for(int i = 0; i <= amount; i++)
        {
            if(i % coins[0] == 0)
            {
                prev[i] = 1;
            }
            else
            {
                prev[i] = 0;
            }
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= amount; j++)
            {
                unsigned int Take = 0;
                unsigned int notTake = prev[j];

                if(coins[i] <= j)
                {
                    Take = curr[j - coins[i]];
                }
            
                curr[j] = Take + notTake;
            }

            prev = curr;
        }

        return prev[amount];
    }
};