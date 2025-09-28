class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>>& adj)
    {
        vector<int> visit_array(adj.size(), 0);
        visit_array[0] = 1;

        queue<int> q;
        q.push(0);

        vector<int> BFS;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            BFS.push_back(node);
            for(auto iter : adj[node])
            {
                if(!visit_array[iter])
                {
                    visit_array[iter] = 1;
                    q.push(iter);
                }
            }
        }
        
        return BFS;
    }
};