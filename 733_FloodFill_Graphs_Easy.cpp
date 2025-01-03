class Solution {
    private:
        void DFS(int sr_row, int sc_col, vector<vector<int>>&answer, vector<vector<int>>& image, int newColor, int delRow[], 
        int delCol[], int initial_color)
        {
            // color with new color
            answer[sr_row][sc_col] = newColor;

            int n = image.size();
            int m = image[0].size();

            // there are exactly 4 neighbours
            for(int i = 0; i < 4; i++)
            {
                int neighbour_row = sr_row + delRow[i]; 
                int neighbour_col = sc_col + delCol[i]; 
                // check for valid coordinate then check for same initial color and unvisited pixel
                if(neighbour_row >= 0 && neighbour_row < n && neighbour_col >= 0 && neighbour_col < m && 
                image[neighbour_row][neighbour_col] == initial_color && 
                answer[neighbour_row][neighbour_col] != newColor)      //It basically checks if it hasn't been already colored
                {
                    DFS(neighbour_row, neighbour_col, answer, image, newColor, delRow, delCol, initial_color); 
                }   
            }
        }

    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, 
        int sc, int color)
        {
            cin.tie(nullptr);
            cout.tie(nullptr);
            ios::sync_with_stdio(false);

            // get initial color
            int initial_color = image[sr][sc]; 
            vector<vector<int>> answer = image; 
            // delta row and delta column for neighbours
            int delRow[] = {-1, 0, +1, 0};
            int delCol[] = {0, +1, 0, -1}; 
            DFS(sr, sc, answer, image, color, delRow, delCol, initial_color); 
            return answer; 
        }
};