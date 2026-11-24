class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False

        multiplier = 0

        number = x

        while number > 9:
            number = number // 10
            multiplier += 1

        k = x
        answer = 0

        while k > 9:
            remainder = k % 10
            answer = answer + remainder * pow(10, multiplier)
            multiplier -= 1
            k = k // 10

        answer += k

        return x == answer
