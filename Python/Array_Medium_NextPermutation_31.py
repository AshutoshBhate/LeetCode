class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        index = 0
        
        for i in range((len(nums) - 2), -1, -1):
            if nums[i] < nums[i + 1]:
                index = i

                break
            elif i == 0:
                nums.reverse()
                return
        
        for i in range((len(nums) - 1), -1, -1):
            if nums[i] > nums[index]:
                nums[index], nums[i] = nums[i], nums[index]

                break
        
        nums[index + 1:] = nums[index + 1:][::-1]

        return