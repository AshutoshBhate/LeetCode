//BFS Approach:

class Solution {
public:
    void BFS(int start, vector<vector<int>>& isConnected, vector<int>& visit_array)
    {
        queue<int> q;
        q.push(start);

        visit_array[start] = 1; //Mark as visited
        
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for (int j = 0; j < isConnected.size(); j++)
            {
                if (isConnected[node][j] == 1 && !visit_array[j])
                {
                    visit_array[j] = 1; //Mark as visited
                    q.push(j);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        vector<int> visit_array(isConnected.size(), 0);
        int count = 0;

        for (int i = 0; i < isConnected.size(); i++)
        {
            if (!visit_array[i])
            {
                count++;
                BFS(i, isConnected, visit_array); //Start BFS for this province
            }
        }

        return count;
    }
};

//DFS Approach:

class Solution {
public:
    void DFS(int node, vector<vector<int>>& isConnected, vector<int>& visit_array)
    {
        visit_array[node] = 1;
        for (int j = 0; j < isConnected.size(); j++)
        {
            if (isConnected[node][j] == 1 && !visit_array[j])
            {
                DFS(j, isConnected, visit_array);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        vector<int> visit_array(isConnected.size(), 0);
        int count = 0;

        for (int i = 0; i < isConnected.size(); i++)
        {
            if (!visit_array[i])
            {
                count++;
                DFS(i, isConnected, visit_array);
            }
        }

        return count;
    }
};

