class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) 
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);
        
        vector<vector<int>> adjList(n + 1);
        vector<int> visited(n + 1, 0);
        bool flag = false;

        for(auto& it : paths)
        {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }

        for(int i = 1; i < adjList.size(); i++)
        {
            for(int k = 1; k <= 4; k++)
            {
                for(int j = 0; j < adjList[i].size(); j++)
                {
                    if(visited[adjList[i][j]] != k)
                    {
                        continue;
                    }
                    flag = true;
                    break;
                }
                if(flag == true)
                {
                    flag = false;
                    continue;
                }
                visited[i] = k;
                break;
            }
        }

        return vector<int>(visited.begin() + 1, visited.end());
    }
};