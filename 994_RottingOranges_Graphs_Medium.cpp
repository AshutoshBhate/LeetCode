class Solution{
    public:
        //Function to find minimum time required to rot all oranges
        int orangesRotting(vector<vector<int>>& grid)
        {
            cin.tie(nullptr);
            cout.tie(nullptr);
            ios::sync_with_stdio(false);

            //Figure out the grid size
            int grid_rows = grid.size();
            int grid_columns = grid[0].size();
            // SC : n x m

            //Store {{row, column}, time}
            queue<pair<pair<int, int>, int>> q;
            // SC : n x m

            //Vector notation : vector<vector<int>> visit_array(n, vector<int>(m, 0));
            int visit_array[grid_rows][grid_columns];

            int countFresh = 0;

            for(int i = 0; i < grid_rows; i++)
            {
                for(int j = 0; j < grid_columns; j ++)
                {
                    //If cell contains rotten oranges
                    if(grid[i][j] == 2)
                    {
                        q.push({{i, j}, 0});

                        //mark as visited (rotten) in visit_array
                        visit_array[i][j] = 2;
                    }
                    else
                    {
                        visit_array[i][j] = 0;
                    }
                    //Count fresh oranges
                    if(grid[i][j] == 1)
                    {
                        countFresh++;
                    }
                }
            }

            int time_max = 0;
            //delta row and delta column (for movement)
            int delta_row[] = {-1, 0, +1, 0};
            int delta_column[] = {0, 1, 0, -1};
            int count = 0;

            //BFS traversal (Until the queue becomes empty)
            while(!q.empty())
            {
                int row = q.front().first.first;
                int column = q.front().first.second;
                int time = q.front().second;
                time_max = max(time_max, time);
                q.pop();

                //Exactly 4 neighbours
                for(int i = 0; i < 4; i++)
                {
                    //neighbouring row and column
                    int neighbour_row = row + delta_row[i];
                    int neighbour_column = column + delta_column[i];

                    //Check for valid cell and them for unvisited fresh orange
                    if(neighbour_row >= 0 && neighbour_row < grid_rows && neighbour_column >= 0 && neighbour_column < grid_columns && visit_array[neighbour_row][neighbour_column] == 0 && grid[neighbour_row][neighbour_column] == 1)
                    {
                        //Push in queue with time increased
                        q.push({{neighbour_row, neighbour_column}, time + 1});

                        //Mark as rotten
                        visit_array[neighbour_row][neighbour_column] = 2;
                        count++;
                    }
                }
            }

            //If all oranges are not rotten
            if(count != countFresh)
            {
                return -1;
            }

            return time_max;
        }
};

// SC total = O(n x m)
// TC total = O(n x m) + O(4 x n x m)
//          = O(n x m)