class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights)
        {
            cin.tie(nullptr);
            cout.tie(nullptr);
            ios :: sync_with_stdio(false);
    
            int n = heights.size();
            int m = heights[0].size();
            
            //{diff, {row, col}}
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>> pq;
    
            pair<int, int> source = {0, 0};
            pair<int, int> destination = {n - 1, m - 1};
    
            vector<vector<int>> distance(n, vector<int>(m, 1e9));
            distance[source.first][source.second] = 0;
    
            pq.push({0, {source.first, source.second}});
    
            int dr[] = {1, 0, -1, 0};
            int dc[] = {0, 1, 0, -1};
    
            while(!pq.empty())
            {
                auto it = pq.top();
                pq.pop();
                int diff  = it.first;
                int row = it.second.first;
                int column = it.second.second;
    
                if(row == n - 1 && column == m - 1)
                {
                    return diff;
                }
    
                for(int i = 0; i < 4; i++)
                {
                    int newr = row + dr[i];
                    int newc = column + dc[i];
    
                    if (newr >= 0 && newc >= 0 && newr < n && newc < m)
                    {
                        int newEffort = max(abs(heights[row][column] - heights[newr][newc]), diff);
                        if(newEffort < distance[newr][newc])
                        {
                            distance[newr][newc] = newEffort;
                            pq.push({distance[newr][newc], {newr, newc}});
                        }
                    }
                }
            }
            return 0;
        }
    };