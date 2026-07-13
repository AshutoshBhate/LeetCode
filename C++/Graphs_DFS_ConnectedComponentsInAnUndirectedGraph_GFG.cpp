class Solution {
  public:
  
    void dfs_helper(int V, vector<vector<int>>& adjList, int node, vector<int>& visited_array, vector<int>& temp)
    {
        visited_array[node] = 1;
        temp.push_back(node);
        
        for(auto& iter : adjList[node])
        {
            if(!visited_array[iter])
            {
                dfs_helper(V, adjList, iter, visited_array, temp);
            }
        }
    }
  
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adjList(V);
        
        vector<vector<int>> answer;
        vector<int> visited_array(V, 0);
        
        for(auto& it : edges)
        {
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        for(int i = 0; i < V; i++)
        {
            vector<int> temp;
            
            if(!visited_array[i])
            {
                int node = i;
                dfs_helper(V, adjList, node, visited_array, temp);
                answer.push_back(temp);
            }
            
        }
        
        
        return answer;
    }
};