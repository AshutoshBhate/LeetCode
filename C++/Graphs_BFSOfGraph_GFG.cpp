class Solution {
  public:
  
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj)
    {
        vector<int> visited_array(adj.size(), 0);
        vector<int> BFS_Answer;
        queue<int> q;
        
        int start_node = 0;
        visited_array[start_node] = 1;
        
        q.push(start_node);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            BFS_Answer.push_back(node);
            
            for(auto it : adj[node])
            {
                if(!visited_array[it])
                {
                    visited_array[it] = 1;
                    q.push(it);
                    
                }
            }
        }
        
        return BFS_Answer;
    }
};