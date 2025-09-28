class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        list_less = []
        list_great = []
        list_pivot = []

        for i in range(len(nums)):
            if nums[i] < pivot:
                list_less.append(nums[i])
            elif nums[i] > pivot:
                list_great.append(nums[i])
            else:
                list_pivot.append(nums[i])
        
        return list_less + list_pivot + list_great