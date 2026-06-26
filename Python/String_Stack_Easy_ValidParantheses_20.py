class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        letter = ""

        for i in range(len(s)):
            if not stack and s[i] in ["]", ")", "}"]:
                return False
            elif s[i] in ["[", "(", "{"]:
                stack.append(s[i])
            elif s[i] in ["]", ")", "}"]:
                if s[i] == "]":
                    letter = "["
                if s[i] == ")":
                    letter = "("
                if s[i] == "}":
                    letter = "{"
                if stack[-1] == letter:
                    stack.pop()
                else:
                    return False
        if not stack:
            return True
        else:
            return False