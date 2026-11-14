class Solution:
    def findMaxAverage(self, nums: list[int], k: int) -> float:
        max_average = float("-inf")

        i = 0
        j = k - 1

        initial_sum = 0

        for x in range(i, j + 1):
            initial_sum += nums[x]

        max_average = max((initial_sum/k), max_average)
        i += 1
        j += 1

        while j < len(nums):
            initial_sum -= nums[i-1]
            initial_sum += nums[j]

            max_average = max((initial_sum/k), max_average)

            i += 1
            j += 1

        return max_average
