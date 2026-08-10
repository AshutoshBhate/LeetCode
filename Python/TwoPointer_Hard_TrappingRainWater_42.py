class Solution:
    def trap(self, height: List[int]) -> int:
        leftMax = height[0]
        rightMax = height[len(height) - 1]
        total = 0

        l = 0
        r = len(height) - 1

        while l <= r:
            if height[l] <= height[r]:
                if height[l] < leftMax:
                    total += leftMax - height[l]
                else:
                    leftMax = height[l]
                l = l + 1
            else:
                if height[r] < rightMax:
                    total += rightMax - height[r]
                else:
                    rightMax = height[r]
                r = r - 1

        return total

'''
    Or inside the while loop you can also do : 
           if height[l] <= height[r]:
                leftMax = max(leftMax, height[l])
                total += leftMax - height[l]
                l += 1
            else:
                rightMax = max(rightMax, height[r])
                total += rightMax - height[r]
                r -= 1 
'''