class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        cin.tie(nullptr);
        cin.tie(nullptr);
        ios::sync_with_stdio(false);

        int max_size = matrix.size();
        vector<vector<int>> new_matrix(matrix.size(), vector<int> (max_size, 0));
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j  < matrix[0].size(); j++)
            {
                new_matrix[j][max_size - i - 1] = matrix[i][j];
            }
        }
        matrix = new_matrix;
    }
};