class Solution {
    public:
        vector<vector<int>> highestPeak(vector<vector<int>>& isWater)
        {
            cin.tie(nullptr);
            cout.tie(nullptr);
            ios :: sync_with_stdio(false);
    
            int m = isWater.size();
            int n = isWater[0].size();
    
            vector<vector<int>> distance_array(m, vector<int>(n, 0));
            vector<vector<int>> visited_array(m, vector<int>(n, 0));
    
            queue<pair<pair<int, int>, int>> q;
    
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(isWater[i][j] == 1)
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
    
            while(!q.empty())
            {
                int row = q.front().first.first;
                int column = q.front().first.second;
                int steps = q.front().second;
                distance_array[row][column] = steps;
                q.pop();
    
                int dRow[] = {1, 0, -1, 0};
                int dColumn[] = {0, 1, 0, -1};
    
                for(int i = 0; i < 4; i++)
                {
                    int n_row = row + dRow[i];
                    int n_column = column + dColumn[i];
    
                    if(n_row >= 0 && n_row < m && n_column >= 0 && n_column < n && 
                    visited_array[n_row][n_column] == 0)
                    {
                        visited_array[n_row][n_column] = 1;
                        q.push({{n_row, n_column}, steps + 1});
                    }
                }
            }     
    
            return distance_array;
        }
    };