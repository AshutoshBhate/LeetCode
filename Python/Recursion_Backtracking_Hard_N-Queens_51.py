class Solution:
    def solve(self, col, board, answer, leftRow, upperDiagonal, lowerDiagonal, n):
        if col == n:
            answer.append(["".join(row) for row in board])
            return
        for row in range(n):
            if leftRow[row] == 0 and lowerDiagonal[row + col] == 0 and upperDiagonal[n - 1 + col - row] == 0:
                board[row][col] = "Q"
                leftRow[row] = 1
                lowerDiagonal[row + col] = 1
                upperDiagonal[n - 1 + col - row] = 1

                self.solve(col + 1, board, answer, leftRow, upperDiagonal, lowerDiagonal, n)

                board[row][col] = "."
                leftRow[row] = 0
                lowerDiagonal[row + col] = 0
                upperDiagonal[n - 1 + col - row] = 0

    def solveNQueens(self, n: int) -> List[List[str]]:
        answer = []
        board = [["." for _ in range(n)] for _ in range(n)]

        leftRow = [0] * n
        upperDiagonal = [0] * (2 * n - 1)
        lowerDiagonal = [0] * (2 * n - 1)

        self.solve(0, board, answer, leftRow, upperDiagonal, lowerDiagonal, n)
        return answer