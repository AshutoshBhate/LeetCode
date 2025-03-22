class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads)
        {
            cin.tie(nullptr);
            cout.tie(nullptr);
            ios :: sync_with_stdio(false);
    
            const long long INF = 1e18;
    
            vector<vector<pair<int ,long long>>> adj(n);
    
            for(auto it : roads)
            {
                adj[it[0]].push_back({it[1], it[2]});
                adj[it[1]].push_back({it[0], it[2]});
            }
    
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
            vector<long long> dist(n, INF);
            vector<int> ways(n, 0);
    
            dist[0] = 0;
            ways[0] = 1;
            pq.push({0, 0});
            long long mod = 1e9 + 7;
    
            while(!pq.empty())
            {
                long long dis = pq.top().first;
                int node = pq.top().second;
    
                pq.pop();
    
                for(auto it : adj[node])
                {
                    int adjNode = it.first;
                    long long edgeW = it.second;
    
                    //This is the first time I am coming
                    //with this short distance
                    if(dis + edgeW < dist[adjNode])
                    {
                        dist[adjNode] = dis + edgeW;
                        pq.push({dis + edgeW, adjNode});
                        ways[adjNode] = ways[node];
                    }
                    else if(dis + edgeW == dist[adjNode])
                    {
                        ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                    }
                }
            }
    
            return ways[n - 1] % mod;
        }
    };
    
    //TC : E log(V)