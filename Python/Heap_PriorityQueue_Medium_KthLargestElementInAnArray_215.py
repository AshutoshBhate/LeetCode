class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = []
        heapLimit = k

        for num in nums:
            heapq.heappush(heap, num)

            if len(heap) > heapLimit:
                heapq.heappop(heap)

        return heap[0]
        