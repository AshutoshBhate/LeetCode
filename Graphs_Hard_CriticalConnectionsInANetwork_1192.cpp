class Solution {
    public:
        vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
        {
            vector<vector<int>> graph(n);
    
            for (auto& conn : connections)
            {
                int u = conn[0], v = conn[1];
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
            
            vector<int> disc(n, -1);
            vector<int> low(n, -1);  
            vector<vector<int>> bridges;
            int time = 0;
            
            function<void(int, int)> dfs = [&](int node, int parent)
            {
                disc[node] = low[node] = time++;
                
                for (int neighbor : graph[node])
                {
                    if (neighbor == parent)
                        continue;
                    
                    if (disc[neighbor] == -1)
                    { 
                        dfs(neighbor, node);
                        low[node] = min(low[node], low[neighbor]);
                    
                        if (low[neighbor] > disc[node])
                        {
                            bridges.push_back({node, neighbor});
                        } 
                    }
                    else
                    {
                        low[node] = min(low[node], disc[neighbor]);
                    }
                }
            };
            dfs(0, -1);
            return bridges;
        }
    };
    