class Solution {
public:

    void DFS(int coordinate_x, int coordinate_y, vector<vector<char>>& board, vector<vector<int>>& visited_array)
    {
        int m = board.size();
        int n = board[0].size();

        visited_array[coordinate_x][coordinate_y] = 1;

        int delta_Row[] = {-1, 0, 1, 0};
        int delta_Column[] = {0, -1, 0, 1};

        for(int i = 0; i < 4; i++)
        {
            int new_X = coordinate_x + delta_Row[i];
            int new_Y = coordinate_y + delta_Column[i];

            if(new_X >= 0 && new_X < m && new_Y >= 0 && new_Y < n && board[new_X][new_Y] == 'O' && visited_array[new_X][new_Y] == 0)
            {
                DFS(new_X, new_Y, board, visited_array);
            }
        }
    }

    void solve(vector<vector<char>>& board)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios :: sync_with_stdio(false);

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited_array(m, vector<int>(n, 0));

        for(int i = 0; i < n; i++)
        {
            if(board[0][i] == 'O' && visited_array[0][i] == 0)
            {
                DFS(0, i, board, visited_array);
            }
        }
        for(int i = 0; i < m; i++)
        {
            if(board[i][n - 1] == 'O' && visited_array[i][n - 1] == 0)
            {
                DFS(i, n - 1, board, visited_array);
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(board[m - 1][i] == 'O' && visited_array[m - 1][i] == 0)
            {
                DFS(m - 1, i, board, visited_array);
            }
        }
        for(int i = 0; i < m; i++)
        {
            if(board[i][0] == 'O' && visited_array[i][0] == 0)
            {
                DFS(i, 0, board, visited_array);
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(visited_array[i][j] == 1)
                {
                    board[i][j] = 'O';
                }
                else
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};