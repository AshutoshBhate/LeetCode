class Solution:
    def beautifulSubarrays(self, nums: List[int]) -> int:
        XORSum = 0
        masterCount = 0
        XORMap = defaultdict(int)

        XORMap[0] = 1

        for i in range(0, len(nums)):

            XORSum = XORSum ^ nums[i]

            remove = XORSum ^ 0

            masterCount += XORMap[remove]

            XORMap[XORSum] += 1

        return masterCount

