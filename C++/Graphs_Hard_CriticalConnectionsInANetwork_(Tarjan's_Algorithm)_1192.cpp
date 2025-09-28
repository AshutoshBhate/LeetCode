class Solution {

private:
    int timer = 1;

private:
    void DFS(int node, int parent, vector<int>& vis, vector<int> adj[], int T_in[], int T_low[],
            vector<vector<int>>& bridges)
    {
        vis[node] = 1;
        T_in[node] = T_low[node] = timer;
        timer++;

        for(auto it : adj[node])
        {
            if(it == parent)
            {
                continue;
            }
            if(vis[it] == 0)
            {
                DFS(it, node, vis, adj, T_in, T_low, bridges);
                T_low[node] = min(T_low[node], T_low[it]);

                //node ---- it
                if(T_low[it] > T_in[node])
                {
                    bridges.push_back({it, node});
                }
            }
            else
            {
                T_low[node] = min(T_low[node], T_in[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
    {
        vector<int> adj[n];

        for(auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);

        int T_in[n];
        int T_low[n];

        vector<vector<int>> bridges;
        DFS(0, -1, vis, adj, T_in, T_low, bridges);

        return bridges;
    }
};

//TC: O(V + 2E)
//SC: O(V + 2E) + O(3N)