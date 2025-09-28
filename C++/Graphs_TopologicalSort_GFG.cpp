//Topological Sort : DFS

class Solution {
  public:
  
    void DFS(int start_node, vector<int>& visited_array, vector<vector<int>>& adj, stack<int>& st)
    {
        visited_array[start_node] = 1;
        
        for(auto iter : adj[start_node])
        {
            if(!visited_array[iter])
            {
                DFS(iter, visited_array, adj, st);
            }
        }
        st.push(start_node);
        
    }
    
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj)
    {
        vector<int> visited_array(adj.size(), 0);
        stack<int> st;

        for(int i = 0; i <  adj.size(); i++)
        {
            if(!visited_array[i])
            {
                DFS(i, visited_array, adj, st);
            }
        }
        
        vector<int> DFS_Answer;
        while(!st.empty())
        {
            DFS_Answer.push_back(st.top());
            st.pop();
        }
        
        return DFS_Answer;
    }
};

//Topological Sort : BFS(Kahn's Algorithm)

class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj)
    {
        vector<int> inDegree(adj.size(), 0);
        vector<int> TopoSort;
        
        for(int i = 0; i < adj.size(); i++)
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
        
        return TopoSort;
        
    }
};