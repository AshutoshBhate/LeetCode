import heapq

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap = []

        for i in range(0, len(stones)):
            heapq.heappush(heap, -stones[i])

        while len(heap) > 1:
            max_1 = -heapq.heappop(heap)
            max_2 = -heapq.heappop(heap)

            if max_1 == max_2:
                continue
            else: 
                heapq.heappush(heap, -(abs(max_1 - max_2)))
        
        if len(heap) == 0:
            return 0
        else:
            return -heapq.heappop(heap)
