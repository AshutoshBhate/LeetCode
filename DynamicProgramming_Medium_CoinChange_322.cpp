//My Solution : 

//Memoization : 

class Solution {
public:

    int min_steps(vector<int> coins, int amount, unordered_map<int, int>& myMap)
    {
        if(amount == 0)
        {
            return 0;
        }
        if(amount < 0)
        {
            return INT_MAX;
        }

        if(myMap.find(amount) != myMap.end())
        {
            return myMap[amount];
        }

        int minimum = INT_MAX;
        for(int i = 0; i < coins.size(); i++)
        {
            int result = min_steps(coins, amount - coins[i], myMap);
            if(result != INT_MAX)
            {
                result += 1;
                minimum = min(minimum, result);
            }
        }

        myMap[amount] = minimum;
        return myMap[amount];
    }

    int coinChange(vector<int>& coins, int amount)
    {
        unordered_map<int, int> myMap;

        int steps = min_steps(coins, amount, myMap);
        if(steps == INT_MAX)
        {
            return -1;
        }
        else
        {
            return steps;
        }
    }
};

//Striver Solution : 

//Memoization : 

class Solution {
public:

    int helper(int index, int target, vector<int>& coins, vector<vector<int>>& dp)
    {
        if(index == 0)
        {
            if(target % coins[0] == 0)
            {
                return target / coins[0];
            }
            else
            {
                return 1e9;
            }
        }
        if(dp[index][target] != -1)
        {
            return dp[index][target];
        }

        int notTake = 0 + helper(index - 1, target, coins, dp);
        int Take = INT_MAX;

        if(coins[index] <= target)
        {
            Take = 1 + helper(index, target - coins[index], coins, dp);
        }

        return dp[index][target] = min(Take, notTake);
    }

    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = helper(n - 1, amount, coins, dp);

        if(ans >= 1e9)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};

//TC : O(N * amount)
//SC : O(N * amount) + O(amount) Auxiliary Stack Space due to recursion

//Tabulation :

class Solution {
public:

    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for(int i = 0; i <= amount; i++)
        {
            if(i % coins[0] == 0)
            {
                dp[0][i] = i / coins[0];
            }
            else
            {
                dp[0][i] = 1e9;
            }
        }

        for(int index = 1; index < n; index++)
        {
            for(int i = 0; i <= amount; i++)
            {
                int notTake = 0 + dp[index - 1][i];
                int Take = INT_MAX;

                if(coins[index] <= i)
                {
                    Take = 1 + dp[index][i - coins[index]];
                }

                dp[index][i] = min(Take, notTake);
            }
        }

        int ans = dp[n - 1][amount];
        if(ans >= 1e9)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};

//TC : O(N * amount)
//SC : O(N * amount)

//Space Optimization :

class Solution {
public:

    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();

        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1, 0);

        for(int i = 0; i <= amount; i++)
        {
            if(i % coins[0] == 0)
            {
                prev[i] = i / coins[0];
            }
            else
            {
                prev[i] = 1e9;
            }
        }

        for(int index = 1; index < n; index++)
        {
            for(int i = 0; i <= amount; i++)
            {
                int notTake = 0 + prev[i];
                int Take = INT_MAX;

                if(coins[index] <= i)
                {
                    Take = 1 + curr[i - coins[index]];
                }

                curr[i] = min(Take, notTake);
            }

            prev = curr;
        }

        int ans = prev[amount];
        if(ans >= 1e9)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};

//TC : O(N * amount)
//SC : O(amount)






