class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
        maxCount = nums[0]
        count_p = nums[0]
        count_n = nums[0]

        for i in range(1, len(nums)):

            curr = nums[i]

            temp = count_p

            count_p = max(curr, temp * curr, count_n * curr)
            count_n = min(curr, temp * curr, count_n * curr)

            maxCount = max(count_p, maxCount)

        return maxCount
        