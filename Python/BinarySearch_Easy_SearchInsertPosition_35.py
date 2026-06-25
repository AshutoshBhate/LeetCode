class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        i = 0
        j = len(nums) - 1

        while i <= j and i < len(nums) and j < len(nums):
            mid = int((i + j)/2) 

            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                i = mid + 1
            else:
                j = mid - 1

        return i
        
        # Linear O(n) traversal which is not needed and exceeds the O(log n) constraint
        # index = 0

        # while(index <= len(nums) - 1):
        #     if nums[index] > target:
        #         return index

        #     index += 1
        
        # return len(nums)