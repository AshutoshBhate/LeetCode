class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        i, j = 0, 0
        answer = ""

        while i < len(word1) and j < len(word2):
            k, l = word1[i], word2[j]

            answer = answer + k + l

            i += 1
            j += 1

        if i < len(word1):
            answer += word1[i:]

        if j< len(word2):
            answer += word2[j:]

        return answer
