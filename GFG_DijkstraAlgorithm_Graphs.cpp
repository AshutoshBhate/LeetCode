class Solution {
    public:
        // Function to find the shortest distance of all the vertices from the source vertex src.
        vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
        {
            int n = adj.size();
    
            //Declare the distance array, one based
            vector<int> dist(n, 1e9);
            dist[src] = 0;  //Source node is always zero
            
            // Priority Queue : pair{weight, current node being processed}
            //We need weight first as we need to process smallest weight out of the priority queue. Smallest distance is always at the top
    
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, src});
            
            while(!pq.empty())
            {
                pair<int, int> topPair = pq.top();
                int d = topPair.first;
                int node = topPair.second;
                
                pq.pop();
                
                // Ignore if we have already found a better way
                if(d > dist[node])
                {
                    continue;
                }
                
                //Adjaceny List : pair{neighboring node, weight}
    
                // Explore the neighbors
                for(auto edge : adj[node])
                {
                    int adjacent_Node = edge.first;
                    int edgeW = edge.second;
                    
                    // Relaxation step
                    if(dist[node] + edgeW < dist[adjacent_Node])
                    {
                        dist[adjacent_Node] = dist[node] + edgeW;
                        pq.push({dist[adjacent_Node], adjacent_Node});
                    }
                }
            }
            
            return dist;
        }
    };
    
    //TC : O(E log(V))
    //Where E = Number of edges and V is the number of nodes