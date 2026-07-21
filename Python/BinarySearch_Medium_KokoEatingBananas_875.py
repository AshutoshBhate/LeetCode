import math

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        max_Element = max(piles)

        min_Count = float('inf')

        left = 1
        right = max_Element

        while left <= right:
            mid = (left + right)//2

            hours = 0

            for i in range(0, len(piles)):
                hours += math.ceil(piles[i]/mid)

            if hours <= h:
                right = mid - 1
                min_Count = min(mid, min_Count)
            else:
                left = mid + 1

        return min_Count



        