class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        i = 0

        stack.append(asteroids[i])
        i += 1

        while i < len(asteroids):
            curr = asteroids[i]

            if not stack:
                stack.append(curr)
                i += 1
                continue

            top = stack[-1]
            topflag = top > 0
            currflag = curr > 0

            if topflag == currflag:
                stack.append(curr)
                i += 1
            elif not topflag and currflag:
                stack.append(curr)
                i += 1
            else:
                if abs(curr) > abs(top):
                    stack.pop()
                elif abs(curr) < abs(top):
                    i += 1
                else:
                    stack.pop()
                    i += 1

        return stack