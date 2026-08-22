class Solution:
    def kthSmallest(self, matrix: list[list[int]], k: int) -> int:
        pq = []

        for row in range(len(matrix)):
            pq.append((matrix[row][0], row, 0))

        heapq.heapify(pq)

        for step in range(k - 1):
            val, row, col = heapq.heappop(pq)

            if col + 1 < len(matrix[0]):
                heapq.heappush(pq, (matrix[row][col + 1], row, col + 1))

        return pq[0][0]