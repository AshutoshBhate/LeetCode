class Solution:
    def dailyTemperatures(self, temperatures: list[int]) -> list[int]:
        stack = []
        answer = [0] * len(temperatures)

        for i in range(0, len(temperatures)):

            if not stack:
                stack.append(i)
            else:
                if temperatures[i] > temperatures[stack[-1]]:
                    while stack and temperatures[i] > temperatures[stack[-1]]:
                        answer[stack[-1]] = i - stack[-1]
                        stack.pop()
                    stack.append(i)
                elif temperatures[i] <= temperatures[stack[-1]]:
                    stack.append(i)

        return answer
