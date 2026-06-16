class Solution:
    def isPalindrome(self, s: str) -> bool:
        s1 = ""
        s2 = ""
        for i in range (len(s) - 1, -1, -1):
            if s[i].isalnum():
                s1 += s[i].lower()
        for i in range (0, len(s)):
            if s[i].isalnum():
                s2 += s[i].lower()
        return s1 == s2