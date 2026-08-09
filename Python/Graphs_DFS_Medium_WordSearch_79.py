class Solution:

    def dfs_helper(self, board, word, index, row, column):
        if index == len(word):
            return True
        if row < 0 or row >= len(board) or column < 0 or column >= len(board[0]) or board[row][column] != word[index]:
            return False

        temp = board[row][column]
        board[row][column] = "#"
        
        directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]

        for delta_row, delta_col in directions:
            new_row = row + delta_row
            new_col = column + delta_col

            if self.dfs_helper(board, word, index + 1, new_row, new_col) == True:
                return True

        board[row][column] = temp

        return False
        

    def exist(self, board: List[List[str]], word: str) -> bool:
        rows = len(board)
        columns = len(board[0])

        for row in range(0, rows):
            for column in range(0, columns):
                if self.dfs_helper(board, word, 0, row, column) == True:
                    return True

        return False