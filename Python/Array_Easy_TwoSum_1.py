# Basic Code TLE : 

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        array = []
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    array = [i, j]
        return array
    
# Actual Two Sum Method : 

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen_dict = {}

        for i, number in enumerate(nums):
            complement = target - number

            if complement in seen_dict:
                return [seen_dict[complement], i]
            
            else:
                seen_dict[number] = i