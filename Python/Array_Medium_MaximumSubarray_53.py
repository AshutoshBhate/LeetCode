class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = float('-inf')
        curr_sum = 0 

        for i in range(0, len(nums)):
            curr_sum += nums[i]
            maxSum = max(curr_sum, maxSum)
            if curr_sum < 0:
                curr_sum = 0
                continue

        return maxSum