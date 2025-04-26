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
                minimum = min(minimum, 1 + result);
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