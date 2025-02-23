class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
        {
            vector<vector<int>> adj(numCourses);
    
            for(auto it : prerequisites)
            {
                adj[it[1]].push_back(it[0]);
            }
    
            vector<int> inDegree(numCourses, 0);
            vector<int> TopoSort;
            
            for(int i = 0; i < numCourses; i++)
            {
                for(auto iter : adj[i])
                { 
                    inDegree[iter]++;
                }
            }
            
            queue<int> q;
            
            for(int i = 0; i < inDegree.size(); i++)
            {
                if(inDegree[i] == 0)
                {
                    q.push(i);
                }
            }
            
            while(!q.empty())
            {
                int node = q.front();
                TopoSort.push_back(node);
                q.pop();
                
                for(auto it : adj[node])
                {
                    inDegree[it]--;
                    if(inDegree[it] == 0)
                    {
                        q.push(it);
                    }
                }
            }
            if(TopoSort.size() == numCourses)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    };