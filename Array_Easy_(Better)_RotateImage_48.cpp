class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);
        
        int space = 0;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = i; j < matrix[0].size(); j++)
            {
                if(i == j)
                {
                    continue;
                }
                space = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = space;
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};