class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
        {
            cin.tie(nullptr);
            cout.tie(nullptr);
            ios :: sync_with_stdio(false);
    
            int m = mat.size();
            int n = mat[0].size();
    
            vector<vector<int>> visited_array(m, vector<int>(n, 0));
            vector<vector<int>> distance_array(m, vector<int>(n, 0));
            queue<pair<pair<int, int>, int>> q;  //{{x, y}, steps}
    
            for(int i = 0; i < m; i ++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(mat[i][j] == 0)
                    {
                        q.push({{i, j}, 0});
                        visited_array[i][j] = 1;
                    }
                    else
                    {
                        visited_array[i][j] = 0;
                    }
                }
            }
    
            //TC : n x m x 4
            while(!q.empty())
            {
                int row = q.front().first.first;
                int column = q.front().first.second;
                int steps = q.front().second;
                q.pop();
    
                distance_array[row][column] = steps;
    
                int deltaRow[] = {-1, 0, 1, 0};
                int deltaColumn[] = {0, 1, 0, -1};
    
                for(int i = 0; i < 4; i++)
                {
                    int neighbour_row = row + deltaRow[i];
                    int neighbour_column = column + deltaColumn[i];
    
                    if(neighbour_row >= 0 && neighbour_row < m && neighbour_column >= 0 && neighbour_column < n && visited_array[neighbour_row][neighbour_column] == 0)
                    {
                        visited_array[neighbour_row][neighbour_column] = 1;
                        q.push({{neighbour_row, neighbour_column}, steps + 1});
                    }
                }
            }
    
            return distance_array;
        }
    };