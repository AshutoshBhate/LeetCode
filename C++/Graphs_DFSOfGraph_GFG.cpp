class Solution {
  public:
  
    void dfs_helper(int node, vector<vector<int>>& adj, vector<int>& visited_array, vector<int>& DFS_Answer)
    {
        visited_array[node] = 1;
        DFS_Answer.push_back(node);
        
        for(auto it : adj[node])
        {
            if(!visited_array[it])
            {
                dfs_helper(it, adj, visited_array, DFS_Answer);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) 
    {
        vector<int> visited_array(adj.size(), 0);
        vector<int> DFS_Answer;
        
        int node = 0;
        
        dfs_helper(node, adj, visited_array, DFS_Answer);
        
        return DFS_Answer;
    }
};