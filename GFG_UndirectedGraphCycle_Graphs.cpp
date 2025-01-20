//Striver Solution:

class Solution {
  private: 
    bool detect(int src, vector<int> adj[], int vis[])
    {
        vis[src] = 1; 
        //Store <source node, parent node>
        queue<pair<int, int>> q; 
        q.push({src, -1});

        //Traverse until queue is not empty
        while(!q.empty())
        {
            int node = q.front().first; 
            int parent = q.front().second; 
            q.pop(); 
        
            //Go to all adjacent nodes
            for(auto adjacentNode: adj[node])
            {
                //If adjacent node is unvisited
                if(!vis[adjacentNode])
                {
                vis[adjacentNode] = 1; 
                q.push({adjacentNode, node}); 
                }
                //If adjacent node is visited and is not it's own parent node
                else if(parent != adjacentNode)
                {
                //Yes it is a cycle
                return true; 
                }
            }
        }      
        //There's no cycle
        return false; 
    }

  public:
    //Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        //Initialise them as unvisited 
        int vis[V] = {0};
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                if(detect(i, adj, vis)) return true; 
            }
        }
        return false; 
    }
};

//GFG Solution:

class Solution {
  private:
    // Helper function to detect a cycle using BFS
    bool detect(int src, vector<vector<int>>& adj, vector<int>& vis)
    {
        vis[src] = 1; 
        // Store <source node, parent node>
        queue<pair<int, int>> q; 
        q.push({src, -1});

        // Traverse until queue is not empty
        while (!q.empty())
        {
            int node = q.front().first; 
            int parent = q.front().second; 
            q.pop(); 
        
            // Go to all adjacent nodes
            for (auto adjacentNode : adj[node])
            {
                // If adjacent node is unvisited
                if (!vis[adjacentNode])
                {
                    vis[adjacentNode] = 1; 
                    q.push({adjacentNode, node}); 
                }
                // If adjacent node is visited and is not its own parent
                else if (parent != adjacentNode)
                {
                    // Cycle detected
                    return true; 
                }
            }
        }      
        // No cycle found
        return false; 
    }

  public:
    // Function to detect cycle in an undirected graph
    bool isCycle(vector<vector<int>>& adj)
    {
        int V = adj.size(); // Number of vertices
        // Initialize all nodes as unvisited
        vector<int> vis(V, 0);
        
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect(i, adj, vis)) 
                    return true; 
            }
        }
        return false; 
    }
};

