class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {

        int rows, columns;

        columns = matrix[0].size();
        rows = matrix.size();
        vector<int> column_array(columns, 1);
        vector<int> row_array(rows, 1);

        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    column_array[j] = 0;
                    row_array[i] = 0;
                } 
            }
        }

        for(int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (row_array[i] == 0 || column_array[j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};