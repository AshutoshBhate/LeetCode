import numpy as np

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)

        arr = np.zeros(n + 1)

        for i in range(len(nums)):
            arr[nums[i]] = 1

        for i in range(len(arr)):
            if arr[i] == 0:
                return i



