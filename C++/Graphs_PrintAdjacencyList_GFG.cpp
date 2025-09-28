class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int num_nodes, vector<pair<int, int>>& edges)
    {
        // Create an adjacency list with num_nodes empty lists.
        vector<vector<int>> adjList(num_nodes);

        // Iterate through each edge and populate the adjacency list.
        for (auto edge : edges)
        {
            int node_1 = edge.first;
            int node_2 = edge.second;

            // Add node_2 to node_1's list and node_1 to node_2's list.
            adjList[node_1].push_back(node_2);
            adjList[node_2].push_back(node_1);
        }

        return adjList;
    }
};