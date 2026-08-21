class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        count = [0] * 26

        for i in range(0, len(tasks)):
            count[ord(tasks[i]) - ord('A')] += 1

        heap = []
        for num in count:
            if num > 0:
                heapq.heappush(heap, -num)

        totalTime = 0

        while heap:
            waiting_line = []
            time_in_that_window = 0
            tasks_to_fill = n + 1

            while tasks_to_fill > 0 and heap:
                waiting_line.append(-heapq.heappop(heap) - 1)
                tasks_to_fill -= 1
                time_in_that_window += 1

            for remaining in waiting_line:
                if remaining > 0:
                    heapq.heappush(heap, -remaining)
            
            if not heap:
                totalTime += time_in_that_window
            else:
                totalTime += (n + 1)

        return totalTime




