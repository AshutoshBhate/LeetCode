class Solution {
public:

    void dfs_helper(int n, int node, vector<vector<int>>& adjList, vector<int>& visited_array, int& totalDegree, int& got_a_node)
    {
        visited_array[node] = 1;
        totalDegree += adjList[node].size();
        got_a_node++;

        for(auto& it : adjList[node])
        {
            if(!visited_array[it])
            {
                dfs_helper(n, it, adjList, visited_array, totalDegree, got_a_node);
            }
            
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        // First we will create an adjacency list
        vector<vector<int>> adjList(n);

        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(it[1]);
            adjList[v].push_back(it[0]);
        }

        vector<int> visited_array(n, 0);
        int totalDegree = 0, got_a_node = 0;
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            if(!visited_array[i])
            {
                int node = i;
                totalDegree = 0;
                got_a_node = 0;
                dfs_helper(n, node, adjList, visited_array, totalDegree, got_a_node);
                if(totalDegree == got_a_node*(got_a_node-1))
                {
                    count++;
                }
            }
            
        }

        return count;
    }
};