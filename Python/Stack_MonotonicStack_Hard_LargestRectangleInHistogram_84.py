'''
Largest Rectangle in Histogram - Monotonic Stack Approach

CORE INTUITION:
For every bar at index 'i', we want to assume it is the shortest bar in a potential 
rectangle and see how far it can expand left and right. To do this, we find:
1. PSE (Previous Smaller Element): The first index to the left that is smaller.
2. NSE (Next Smaller Element): The first index to the right that is smaller.

KEY INSIGHT #1: THE WIDTH FORMULA
The total width this bar can span is simply: nse[i] - pse[i] - 1
- If no smaller element exists on the left, PSE defaults to -1.
- If no smaller element exists on the right, NSE defaults to n (array length).
- We don't need to manually split the math into "forward" and "backward" variables 
  and check bounds; subtracting the indices naturally handles the math!

KEY INSIGHT #2: HANDLING DUPLICATES (THE "OWNERSHIP" TRICK)
Look at the while loops: PSE uses non-strict '<=', while NSE uses strict '<'.
Why? When we have identical heights like [2, 2, 2]:
- If both loops used strict '<', all three 2s would look left/right, see no *strictly* 
  smaller numbers, and all three would calculate the exact same massive width of 3.
- By making one side '<=' and the other '<', we force the duplicates to crash into 
  each other from one direction, but slide past from the other.
- This makes the RIGHT-MOST duplicate act as the "anchor"—it calculates the full 
  maximum width. The earlier duplicates calculate truncated, smaller widths. 
- The max area remains perfectly correct! (Note: Mastering this strict/non-strict trick 
  is mandatory for problems like "Sum of Subarray Minimums" to prevent double-counting).
  
To handle duplicate heights, we alternate the strictness of our stack logic: 
- PSE uses '<=' to pop elements (skips over duplicates, finding STRICTLY smaller boundaries).
- NSE uses '<' to pop elements (stops at duplicates, finding SMALLER OR EQUAL boundaries).

Walkthrough: How alternating benefits us using [1, 2(a), 2(b), 2(c), 3]:
By using one strict and one non-strict boundary, we force the right-most duplicate to 
claim the entire block. Let's look at the 2s (indices 1, 2, and 3):

- 2(a) at index 1: 
  PSE (<=) scans left, skips nothing, and finds '1' at index 0. 
  NSE (<) scans right, hits duplicate 2(b) at index 2, and stops as a boundary. 
  Width: 2 - 0 - 1 = 1. (Truncated rectangle)

- 2(b) at index 2:
  PSE (<=) scans left, pops (skips over) 2(a), and finds '1' at index 0.
  NSE (<) scans right, hits duplicate 2(c) at index 3, and stops.
  Width: 3 - 0 - 1 = 2. (Truncated rectangle)

- 2(c) at index 3:
  PSE (<=) scans left, pops BOTH 2(b) and 2(a), and finds '1' at index 0. 
  NSE (<) scans right, sees '3' (which is larger, so it pops it), and goes to the end (index 5).
  Width: 5 - 0 - 1 = 4. (Captures the FULL block! Indices 1, 2, 3, 4 are all >= 2. Area = 8)

KEY INSIGHT #3: STACK BOILERPLATE
By pre-filling the answer arrays with their absolute maximum boundaries (`-1` for left, 
`n` for right), we avoid complex bounds-checking later. 
For every element:
1. Pop elements from the stack that violate our monotonic rule.
2. If the stack becomes empty, our current element is the smallest seen so far, so we 
   just append it (the array already holds the `-1` or `n` default).
3. If the stack is not empty, the top of the stack is our boundary. Update the answer 
   array, then append the current index.
'''

class Solution:

    def findNSE(self, n, heights):
        stack = []
        answer = [n] * n

        for i in range(len(heights) - 1, -1, -1):
            while stack and heights[i] < heights[stack[-1]]:
                stack.pop()
            if not stack:
                stack.append(i)
                continue
            answer[i] = stack[-1]
            stack.append(i)

        return answer

    def findPSE(self, n, heights):
        stack = []
        answer = [-1] * n

        for i in range(0, len(heights)):
            while stack and heights[i] <= heights[stack[-1]]:
                stack.pop()
            if not stack:
                stack.append(i)
                continue
            answer[i] = stack[-1]
            stack.append(i)

        return answer


    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)

        nse = self.findNSE(n, heights)
        pse = self.findPSE(n, heights)

        maxSum = float('-inf')

        for i in range(0, len(heights)):

            width = nse[i] - pse[i] - 1

            curr_sum = width * heights[i]
            maxSum = max(curr_sum, maxSum)

        return maxSum
