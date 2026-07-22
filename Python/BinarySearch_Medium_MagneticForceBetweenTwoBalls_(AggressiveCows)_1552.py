class Solution:

    def canFit(self, array, distance, numberOfBalls) -> bool:
        currBallcount = 1
        last = array[0]

        for i in range(1, len(array)):
            if array[i] - last >= distance:
                currBallcount += 1
                last = array[i]
        if currBallcount < numberOfBalls:
            return False
        else:
            return True        

    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        max_Count = float('-inf')

        left = 0
        right = position[len(position) - 1]

        while left <= right:
            mid = (left + right) // 2

            if self.canFit(position, mid, m) == False:
                right = mid - 1
            else:
                max_Count = max(mid, max_Count)
                left = mid + 1

        return max_Count