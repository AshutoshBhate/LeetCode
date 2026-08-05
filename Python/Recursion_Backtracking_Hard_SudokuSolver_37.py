# Time Limit Exceeded Code, not as fast as the same algorithm in C++ language, have to find a 
# better method

class Solution:

    def isSafe(self, row, col, board, c):
        for i in range(0, 9):
            if board[i][col] == c:
                return False
            if board[row][i] == c:
                return False
            if board[3*(row//3) + i//3][3*(col//3) + i%3] == c:
                return False
        return True

    def solve(self, board):
        for i in range(0, len(board)):
            for j in range(0, len(board[0])):
                if board[i][j] == '.':
                    for c in map(str, range(1, 10)):
                        if self.isSafe(i, j, board, c) == True:
                            board[i][j] = c
                            if self.solve(board) == True:
                                return True
                            else:
                                board[i][j] = '.'
                    return False

        return True


    def solveSudoku(self, board: List[List[str]]) -> None:
        self.solve(board)
        