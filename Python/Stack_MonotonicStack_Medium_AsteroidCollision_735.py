# My version : 

class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []

        i = 0

        while i < len(asteroids):

            if not stack:
                stack.append(asteroids[i])
                i += 1
                continue

            while stack[-1] > 0 and asteroids[i] < 0:
                if abs(stack[-1]) < abs(asteroids[i]):
                    stack.pop()
                    if not stack:
                        stack.append(asteroids[i])
                        i += 1
                        break
                elif abs(stack[-1]) == abs(asteroids[i]):
                    stack.pop()
                    i += 1
                    break
                else:
                    i += 1
                    break
            if i >= len(asteroids):
                break

            if not stack:
                continue

            elif stack[-1] < 0 and asteroids[i] > 0:
                stack.append(asteroids[i])
                i += 1
            elif stack[-1] > 0 and asteroids[i] > 0:
                stack.append(asteroids[i])
                i += 1
            else:
                stack.append(asteroids[i])
                i += 1

        return stack
        
# Gemini's version :       

class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []

        for ast in asteroids:
            if ast > 0:
                stack.append(ast)
            else:
                while stack and stack[-1] > 0 and stack[-1] < abs(ast):
                    stack.pop()

                if stack and stack[-1] == abs(ast):
                    stack.pop()
                elif not stack or stack[-1] < 0:
                    stack.append(ast)

        return stack