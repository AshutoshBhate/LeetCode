class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        count_1 = 0
        count_2 = 0
        ele_1 = float('-inf')
        ele_2 = float('-inf')
        answer = []

        for i in range(0, len(nums)):
            if count_1 == 0 and nums[i] != ele_2:
                ele_1 = nums[i]
                count_1 += 1
            elif count_2 == 0 and nums[i] != ele_1:
                ele_2 = nums[i]
                count_2 += 1
            elif ele_1 == nums[i]:
                count_1 += 1
            elif ele_2 == nums[i]:
                count_2 += 1
            else:
                count_1 -= 1
                count_2 -= 1
        
        count_1 = 0
        count_2 = 0

        for i in range(0, len(nums)):
            if nums[i] == ele_1:
                count_1 += 1
            if nums[i] == ele_2:
                count_2 += 1
        
        if count_1 > len(nums)/3:
            answer.append(ele_1)
        if count_2 > len(nums)/3:
            answer.append(ele_2)

        return answer
            