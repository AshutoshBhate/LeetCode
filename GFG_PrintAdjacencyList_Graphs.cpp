class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges)
    {
        // Create an adjacency list with V empty lists.
        vector<vector<int>> adjList(V);

        // Iterate through each edge and populate the adjacency list.
        for (auto edge : edges)
        {
            int u = edge.first;
            int v = edge.second;

            // Add v to u's list and u to v's list.
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        return adjList;
    }
};