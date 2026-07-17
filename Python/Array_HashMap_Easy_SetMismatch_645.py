# Optimal Solution
#
# Intuition:
# Let the repeated number be 'x' and the missing number be 'y'.
# 1. Sum of elements in nums (x_1) minus sum of first n natural numbers (y_1):
#    x_1 - y_1 = x - y    --> (Equation 1)
# 
# 2. Sum of squares of elements in nums (x_2) minus sum of squares of first n natural numbers (y_2):
#    x_2 - y_2 = x^2 - y^2 = (x - y) * (x + y)    --> (Equation 2)
#
# From Equation 1 and Equation 2:
#    x + y = (x_2 - y_2) / (x - y) = (x_2 - y_2) / (x_1 - y_1)
#
# Solving for x (repeated_value):
#    Add (x - y) and (x + y):
#    2 * x = (x_1 - y_1) + ((x_2 - y_2) / (x_1 - y_1))
#    x = [(x_1 - y_1) + ((x_2 - y_2) / (x_1 - y_1))] / 2
#
# Solving for y (missing):
#    y = x - (x_1 - y_1)
#
# This allows us to find both numbers in O(N) time and O(1) auxiliary space without modifying the array.

class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        x_1 = 0
        x_2 = 0
        n = len(nums)

        for i in range(0, len(nums)):
            x_1 += nums[i]
        y_1 = (n * (n + 1)) // 2

        for i in range(0, len(nums)):
            x_2 += (nums[i]**2)

        y_2 = (n * (n + 1) * ((2 * n) + 1)) // 6

        repeated_value = int((((x_2 - y_2)/(x_1 - y_1)) + (x_1 - y_1)) // 2)

        missing = int(repeated_value - x_1 + y_1)

        return [repeated_value, missing]