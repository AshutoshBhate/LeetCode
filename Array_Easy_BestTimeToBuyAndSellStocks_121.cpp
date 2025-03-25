class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int minimum = prices[0], cost = 0, profit = 0;

        for(int i = 1; i < prices.size(); i++)
        {
            cost = prices[i] - minimum;
            minimum = min(minimum, prices[i]);
            profit = max(profit, cost);
        }

        return profit;
    }
};