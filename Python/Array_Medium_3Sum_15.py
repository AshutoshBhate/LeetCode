# Better Approach : 

class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        tuple_storing_set = set()


        for i in range(0, len(nums)):
            seen = set()
            for j in range(i + 1, len(nums)):
                

                complement = -(nums[i] + nums[j])
                if complement not in seen:
                    seen.add(nums[j])
                else:
                    triplet = sorted([nums[i], nums[j], complement])
                    tuple_storing_set.add(tuple(triplet))

        return [list(t) for t in tuple_storing_set]
    
# TC: O(N^2)
# SC: O(N^2) Worst Case

# Optimal Approach : 

class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        answer = []
        nums.sort()

        for i in range(0, len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            j = i + 1
            k = len(nums) - 1

            while j < k:
                sum = nums[i] + nums[j] + nums[k]

                if sum < 0:
                    j += 1
                elif sum > 0:
                    k -= 1
                else:
                    res = list([nums[i], nums[j], nums[k]])
                    answer.append(res)
                    j += 1
                    k -= 1

                    while j < k - 1 and nums[j] == nums[j - 1]:
                        j += 1
                    while k > j and nums[k] == nums[k + 1]:
                        k -= 1
        
        return answer
    
# TC : O(N Log N) + O(N^2)
# SC : O(N)

                



