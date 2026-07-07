# Solution using a visited_array:

class Solution:

    def helper(self, nums, result, ds, visited_array):
        if len(ds) == len(nums):
            result.append(ds[:])
            return
        
        for i in range(0, len(nums)):
            if not visited_array[i]:
                ds.append(nums[i])
                visited_array[i] += 1
                self.helper(nums, result, ds, visited_array)
                ds.pop()
                visited_array[i] = 0


    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        ds = []
        visited_array = [0] * len(nums)

        self.helper(nums, result, ds, visited_array)

        return result
        
# Solution using swapping: 

class Solution:

    def helper(self, nums, index, answer):
        if index == len(nums):
            answer.append(nums[:])
            return
        
        for i in range(index, len(nums)):
            nums[index], nums[i] = nums[i], nums[index]
            self.helper(nums, index + 1, answer)
            nums[index], nums[i] = nums[i], nums[index]

    def permute(self, nums: List[int]) -> List[List[int]]:
        answer = []
        index = 0

        self.helper(nums, index, answer)

        return answer
        

