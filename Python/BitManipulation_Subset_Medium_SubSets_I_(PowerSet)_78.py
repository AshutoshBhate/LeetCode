class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        answer = []
        for i in range(0, ((1<<n))):
            subset = []
            for j in range(0, n):
                if (i & 1<<j) != 0:
                    subset.append(nums[j])
            
            answer.append(subset)
        
        return answer
