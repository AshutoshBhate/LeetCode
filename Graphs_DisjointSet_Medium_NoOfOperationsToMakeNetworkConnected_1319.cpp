class DisjointSet
{
    public:
        vector<int> rank, parent, size;

        DisjointSet(int n)
        {
            rank.resize(n+1, 0);
            parent.resize(n + 1);
            size.resize(n + 1);


            for(int i = 0; i <= n; i++)
            {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUPar(int node)
        {
            if(node == parent[node])
            {
                return node;
            }
            else
            {
                return parent[node] = findUPar(parent[node]);
            }
        }

        void unionByRank(int u, int v)
        {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v)
            {
                return;
            }
            if(rank[ulp_u] < rank[ulp_v])
            {
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u] > rank[ulp_v])
            {
                parent[ulp_v] = ulp_u;
            }
            else    //When the rank of the ultimate parents is the same
            {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++; 
            }
        }

        void unionBySize(int u, int v)
        {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v)
            {
                return;
            }

            if(size[ulp_u] < size[ulp_v])
            {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else
            {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios :: sync_with_stdio(false);

        DisjointSet ds(n);

        int cntExtra = 0;

        for(auto it : connections)
        {
            int u = it[0];
            int v = it[1];

            if(ds.findUPar(u) == ds.findUPar(v))
            {
                cntExtra++;
            }
            else
            {
                ds.unionBySize(u, v);
            }
        }

        int cntConnectedComponents = 0;
        for(int i = 0; i < n; i++)
        {
            if(ds.parent[i] == i)
            {
                cntConnectedComponents++;
            }
        }

        int ans = cntConnectedComponents - 1;
        if(cntExtra >= ans)
        {
            return ans;
        }
        else
        {
            return -1;
        }
    }
};