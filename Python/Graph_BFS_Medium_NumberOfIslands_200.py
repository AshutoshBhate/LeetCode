class Solution:

    def bfs_helper(self, row, col, grid, visited_matrix):
        visited_matrix[row][col] = '1'
        q = deque()
        q.append((row, col))
        m = len(grid)
        n = len(grid[0])

        while q:
            row, col = q.popleft()

            directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

            for delta_row, delta_col in directions:
                new_row = row + delta_row
                new_col = col + delta_col

                if new_row >= 0 and new_row < m and new_col >= 0 and new_col < n and grid[new_row][new_col] == '1' and visited_matrix[new_row][new_col] != '1':
                    q.append((new_row, new_col))
                    visited_matrix[new_row][new_col] = '1'




    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])
        count = 0

        visited_matrix = [['0'] * n for _ in range(m)]

        for row in range(0, m):
            for col in range(0, n):
                if visited_matrix[row][col] == '0' and grid[row][col] == '1':
                    self.bfs_helper(row, col, grid, visited_matrix)
                    count += 1

        return count