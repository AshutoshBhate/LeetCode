class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        intervals = sorted(intervals)
        answer = []

        current_begin = intervals[0][0]
        current_end = intervals[0][1]

        for interval in intervals[1:]:
            if interval[0] <= current_end:
                current_end = max(current_end, interval[1])
            elif interval[0] > current_end:
                answer.append([current_begin, current_end])
                current_begin = interval[0]
                current_end = interval[1]

        answer.append([current_begin, current_end])

        return answer
