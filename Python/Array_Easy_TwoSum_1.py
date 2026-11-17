# Basic Code TLE : 

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        array = []
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    array = [i, j]
        return array
    
# Actual with enumerate : 

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen_dict = {}

        for i, number in enumerate(nums):
            complement = target - number
            if number in seen_dict:
                return [seen_dict[number], i]
            else:
                seen_dict[complement] = i

        return []

# Actual my new solution : 
                
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        complement_dict = defaultdict(int)

        for i in range(0, len(nums)):
            if nums[i] not in complement_dict:
                complement = target - nums[i]
                complement_dict[complement] = i
            else:
                return [complement_dict[nums[i]], i]

        return []

        
        