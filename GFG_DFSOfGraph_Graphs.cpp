class Solution{
    private:
        void DFS(int node, vector<vector<int>>& adj, vector<int>& visit_array, vector<int>& DFS_answer)
        {
            visit_array[node] = 1;
            DFS_answer.push_back(node);

            //Traverse all it's neighbours
            for(auto iter : adj[node])
            {
                if(!visit_array[iter])
                {
                    DFS(iter, adj, visit_array, DFS_answer);
                }
            }
        }

    public:
        //Function to return a list containing the DFS traversal of the graph
        vector<int> dfsOfGraph(vector<vector<int>>& adj)
        {
            vector<int> visit_array(adj.size(), 0);
            int start = 0;
            vector<int> DFS_answer;
            DFS(start, adj, visit_array, DFS_answer);
            return DFS_answer;
        }
};