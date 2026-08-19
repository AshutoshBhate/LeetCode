class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.heapLimit = k
        self.heap = []

        for i in range(0, len(nums)):
            heapq.heappush(self.heap, nums[i])
        

    def add(self, val: int) -> int:

        heapq.heappush(self.heap, val)

        if len(self.heap) < self.heapLimit:
            return -1
        else:
            while len(self.heap) > self.heapLimit:
                heapq.heappop(self.heap)

        return self.heap[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)