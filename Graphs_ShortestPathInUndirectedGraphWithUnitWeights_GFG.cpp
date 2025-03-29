class Solution{
    public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src)
    {
        int V = adj.size();  // Number of vertices
          
        // Initialize distances with a large value (using 1e9 as INF)
        vector<int> dist(V, 1e9);
        queue<int> q;
        
        dist[src] = 0;
        q.push(src);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
        
            // Traverse the already built adjacency list for node
            for(auto neighbor : adj[node])
            {
                if(dist[node] + 1 < dist[neighbor])
                {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }
          
        // Replace unreachable vertices (still 1e9) with -1
        for(int i = 0; i < V; i++)
        {
            if(dist[i] == 1e9)
            {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};