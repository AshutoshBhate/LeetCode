class Solution:
    def findMin(self, nums: List[int]) -> int:

        left = 0
        right = len(nums) - 1
        minNumber = float('inf')

        while left <= right:
            mid = (left + right) // 2
            
            if nums[left] <= nums[mid]:
                minNumber = min(nums[left], minNumber)
                left = mid + 1
            else:
                minNumber = min(nums[mid], minNumber)
                right = mid - 1
        
        return minNumber

        