class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefixSum = 0
        prefixMap = defaultdict(int)
        masterCount = 0

        prefixMap[0] = 1

        for i in range(0, len(nums)):
            prefixSum += nums[i]

            if (prefixSum - k) in prefixMap:
                masterCount += prefixMap[prefixSum - k] 

            prefixMap[prefixSum] +=1

    
        return masterCount

            
