//My Solution:

class Solution {
    public:
        int findJudge(int n, vector<vector<int>>& trust)
        {
            vector<vector<int>> adjacency_list(n + 1);
            vector<int> inDegree_array(n + 1, 0);
    
            for(auto it : trust)
            {
                adjacency_list[it[0]].push_back(it[1]);
            }
    
            for(int i = 1; i <= n; i++)
            {
                for(auto iter : adjacency_list[i])
                {
                    inDegree_array[iter] += 1;
                }
            }
    
            for(int i = 1; i <= n; i++)
            {
                if((inDegree_array[i] == n - 1) && (adjacency_list[i].empty()))
                {
                    return i;
                }
            }
    
            return -1;
        }
    };
    
    //Optimal Solution:
    
    // class Solution {
    // public:
    //     int findJudge(int n, vector<vector<int>>& trust) {
    //         vector<int> trustScore(n + 1, 0);
            
    //         // Update trust scores for each trust relation.
    //         for (const auto& t : trust) {
    //             int a = t[0], b = t[1];
    //             trustScore[a]--;  // a trusts someone
    //             trustScore[b]++;  // b gets trusted by someone
    //         }
            
    //         // The judge should be trusted by everyone else: trustScore equals n - 1.
    //         for (int i = 1; i <= n; i++) {
    //             if (trustScore[i] == n - 1) return i;
    //         }
    //         return -1;
    //     }
    // };
    