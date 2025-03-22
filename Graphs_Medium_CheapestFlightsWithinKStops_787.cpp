class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
        {
            cin.tie(nullptr);
            cout.tie(nullptr);
            ios :: sync_with_stdio(false);
    
            //Creating a graph adjacency list
            vector<vector<pair<int, int>>> adj(n);  //{node, cost}
    
            int no_flights = flights.size();
    
            for(int i = 0; i < no_flights; i++)
            {
                adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
            }
    
            queue<pair<int, pair<int, int>>> q;  //{stops, {source, distance}}
    
            q.push({0, {src, 0}});
            vector<int> dist(n, 1e9);
            dist[src] = 0;
    
            while(!q.empty())
            {
                auto it = q.front();
                q.pop();
    
                int stops = it.first;
                int node = it.second.first;
                int cost = it.second.second;
    
                if(stops > k)
                {
                    continue;
                }
                for(auto iter : adj[node])
                {
                    int adjNode = iter.first;
                    int edW = iter.second;
    
                    if(cost + edW < dist[adjNode] && stops <= k)
                    {
                        dist[adjNode] = cost + edW;
                        q.push({stops + 1, {adjNode, cost + edW}});
                    }
                }
    
            }
    
            if(dist[dst] == 1e9)
            {
                return -1;
            }
            else
            {
                return dist[dst];
            }
        }
    };
    
    //Dijkstra algorithm : E log(V)
    //This algorithm : O(E * K)