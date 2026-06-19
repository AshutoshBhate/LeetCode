class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dict_1 = {}

        for i in range(len(nums)):
            if nums[i] in dict_1:
                dict_1[nums[i]] += 1
            else:
                dict_1[nums[i]] = 1
        
        for key, count in dict_1.items():
            if count > int(len(nums)/2):
                return key
        return 0