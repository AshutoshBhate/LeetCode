class Solution {
public:

    bool dfs_helper(vector<vector<char>>& board, string& word, int index, int row, int column)
    {
        if(index == word.size())
        {
            return true;
        }
        if(row < 0 || row >= board.size() || column < 0 || column >= board[0].size() || board[row][column] != word[index])
        {
            return false;
        }

        char temp = board[row][column];
        board[row][column] = '#';

        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        for(auto& it : directions)
        {
            int new_row = row + it.first;
            int new_col = column + it.second;

            if(dfs_helper(board, word, index + 1, new_row, new_col) == true)
            {
                return true;
            }
        }

        board[row][column] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int rows = board.size();
        int columns = board[0].size();

        for(int row = 0; row < rows; row++)
        {
            for(int column = 0; column < columns; column++)
            {
                if(dfs_helper(board, word, 0, row, column) == true)
                {
                    return true;
                }
            }
        }

        return false;
    }
};