class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minimum = prices[0]
        profit = 0

        for i in range(1, len(prices)):
            number = prices[i] - minimum
            minimum = min(prices[i], minimum)

            profit = max(profit, number)
        
        return profit
