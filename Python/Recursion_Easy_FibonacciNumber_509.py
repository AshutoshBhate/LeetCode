# Solution 1 (Recursive, O(2^n) time) :

class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        elif n == 1:
            return 1
        else:
            return self.fib(n - 2) + self.fib(n - 1)

# Solution 2 (Iterative, O(n) time, O(1) space) :

class Solution:
    def fib(self, n: int) -> int:

        if n == 0:
            return 0
        if n == 1:
            return 1

        a, b = 0, 1

        for i in range(2, n + 1):
            c = b
            b = a + b
            a = c

        return b
