class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat)
    {
        int m = mat.size(), n = mat[0].size();

        // Step 1: Create a mapping of matrix elements to their (row, col) positions
        unordered_map<int, pair<int, int>> position;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                position[mat[i][j]] = {i, j};
            }
        }

        // Step 2: Initialize row and column counters
        vector<int> rowCount(m, 0); // Tracks painted cells in each row
        vector<int> colCount(n, 0); // Tracks painted cells in each column

        // Step 3: Process the elements in `arr`
        for (int index = 0; index < arr.size(); ++index)
        {
            int element = arr[index];

            // Find the position of the current element in the matrix
            auto [row, col] = position[element];

            // Increment row and column counters
            rowCount[row]++;
            colCount[col]++;

            // Check if the current row or column is fully painted
            if (rowCount[row] == n || colCount[col] == m)
            {
                return index; // Return the index of the first complete operation
            }
        }

        return -1; // If no row/column is fully painted
    }
};
