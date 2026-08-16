class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dq = deque()
        answer = []

        for i in range(0, len(nums)):
            if dq and dq[0] <= i - k:
                dq.popleft()
            while dq and nums[i] >= nums[dq[-1]]:
                dq.pop()

            dq.append(i)

            if i >= k - 1:
                answer.append(nums[dq[0]])

        return answer    
