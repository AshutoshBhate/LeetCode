class Solution {
public:

    void bfs_helper(int row, int col, vector<vector<char>>& visited_matrix, vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        visited_matrix[row][col] = '1';
        queue<pair<int, int>> q;

        q.push({row, col});

        while(!q.empty())
        {
            row = q.front().first;
            col = q.front().second;

            q.pop();

            vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};


            for(auto& it : directions)
            {
                int delta_row = it.first;
                int delta_col = it.second;

                int new_row = row + delta_row;
                int new_col = col + delta_col;

                if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && visited_matrix[new_row][new_col] != '1' && grid[new_row][new_col] == '1')
                {
                    visited_matrix[new_row][new_col] = '1';
                    q.push({new_row, new_col});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<vector<char>> visited_matrix(m, vector<char>(n, '0'));

        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(visited_matrix[row][col] == '0' && grid[row][col] == '1')
                {
                    bfs_helper(row, col, visited_matrix, grid);
                    count++;
                }
            }
        }

        return count;
    }
};