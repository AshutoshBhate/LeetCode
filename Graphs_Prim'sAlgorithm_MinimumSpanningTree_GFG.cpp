class Solution {
    public:
      // Function to find sum of weights of edges of the Minimum Spanning Tree.
      int spanningTree(int V, vector<vector<int>> adj[])
      {
          priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<pair<int, int>>> pq;
          
          vector<int> visited(V, 0);
          
          //No need to store the parent as we only want the sum of the weights of the MST
          
          //{weight, node}
          pq.push({0, 0});
          
          int sum = 0;
          
          while(!pq.empty())
          {
              auto it = pq.top();
              pq.pop();
              
              int node = it.second;
              int weight = it.first;
              
              if(visited[node] == 1)
              {
                  continue;
              }
              else
              {
                  //Add it to the MST
                  visited[node] = 1;
                  sum = sum += weight;
                  
                  for(auto iter : adj[node])
                  {
                      int adjNode = iter[0];
                      int edgeW = iter[1];
                      
                      if(!visited[adjNode])
                      {
                          pq.push({edgeW, adjNode});
                      }
                      else
                      {
                          continue;
                      }
                      
                  }
              }
          }
          
          return sum;
      }
  };