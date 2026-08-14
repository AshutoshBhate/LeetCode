'''
 * Problem: Sum of Subarray Minimums (LeetCode 907)
 * Pattern: Monotonic Stack with Subarray Bounds
 *
 * Key Concepts:
 * 1. Index-Based Stack: We push array indices (i) to calculate distance 
 *    spans: left_count = i - pse[i] and right_count = nse[i] - i.
 * 2. Virtual Boundaries:
 *    - Default PSE = -1 (extends reach to the left boundary).
 *    - Default NSE =  n (extends reach to the right boundary).
 * 3. Asymmetric Bounds for Duplicates:
 *    - PSE finds Previous STRICTLY Smaller Element (<) by popping stack top >= arr[i].
 *    - NSE finds Next Smaller OR EQUAL Element (<=) by popping stack top > arr[i].
 *    - This asymmetry breaks ties for duplicate values (e.g., [2, 2]) and 
 *      prevents double-counting subarrays.
 '''

class Solution:

    def findNSE(self, n, arr) -> List[int]:
        stack = []
        answer = [n] * n

        for i in range(len(arr) - 1, -1, -1):
            while stack and arr[i] < arr[stack[-1]]:
                stack.pop()
            if not stack:
                stack.append(i)
                continue
            answer[i] = stack[-1]
            stack.append(i)
        return answer

    def findPSE(self, n, arr) -> List[int]:
        stack = []
        answer = [-1] * n

        for i in range(0, len(arr)):
            while stack and arr[i] <= arr[stack[-1]]:
                stack.pop()
            if not stack:
                stack.append(i)
                continue
            answer[i] = stack[-1]
            stack.append(i)
        
        return answer

    def sumSubarrayMins(self, arr: List[int]) -> int:
        n = len(arr)
        MOD = int(1e9 + 7)
        totalSum = 0

        nse = self.findNSE(n, arr)
        pse = self.findPSE(n, arr)

        for i in range(0, len(arr)):
            leftbound = i - pse[i]
            rightbound = nse[i] - i

            multiplication = (leftbound * rightbound) % MOD
            sum_no = (multiplication * arr[i]) % MOD
            totalSum = (totalSum + sum_no) % MOD

        return totalSum
        