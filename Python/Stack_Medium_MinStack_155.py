class MinStack:

    def __init__(self):
        self.stack = []
        self.minStack = []

    def push(self, value: int) -> None:
        self.stack.append(value)
        if not self.minStack or self.minStack[-1] >= value:
            self.minStack.append(value)

    def pop(self) -> None:
        num = self.stack.pop()
        if self.minStack[-1] == num:
            self.minStack.pop()

    def top(self) -> int:
        top = self.stack[-1]
        return top

    def getMin(self) -> int:
        return self.minStack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(value)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
