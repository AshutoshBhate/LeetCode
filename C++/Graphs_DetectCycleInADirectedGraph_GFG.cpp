class Solution {
    public:
      // Function to detect cycle in a directed graph.
      bool isCyclic(vector<vector<int>> &adj)
      {
          int V = adj.size();
          
          int indegree[V] = {0};
          for(int i = 0; i < V; i++)
          {
              for(auto it : adj[i])
              {
                  indegree[it]++;
              }
          }
          
          queue<int> q;
          
          for(int i = 0; i < V; i++)
          {
              if(indegree[i] == 0)
              {
                  q.push(i);
              }
          }
          
          int count = 0;
          
          while(!q.empty())
          {
              int node = q.front();
              q.pop();
              count++;
              
              //Node is in the toposort, so please remove it from the indegree
              
              for(auto it : adj[node])
              {
                  indegree[it]--;
                  if(indegree[it] == 0)
                  {
                      q.push(it);
                  }
              }
          }
          
          if(count == V)
          {
              return false;
          }
          else
          {
              return true;
          }
      }
  };