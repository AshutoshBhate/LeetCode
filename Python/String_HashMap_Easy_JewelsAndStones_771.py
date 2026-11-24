class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:

        answer = []
        jewel_set = set()
        for i in jewels:
            jewel_set.add(i)

        for i in stones:
                if i in jewel_set:
                    answer.append(i)

        return len(answer)
