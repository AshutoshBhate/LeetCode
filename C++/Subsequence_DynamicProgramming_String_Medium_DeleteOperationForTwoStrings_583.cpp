//This is going to be a direct Space Optimization solution, please refer to the previous problems for the the whole 3 solutions

class Solution {
public:
    int minDistance(string word1, string word2)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);
        
        int m = word1.size();
        int n = word2.size();

        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for(int i = 0; i <= n; i++)
        {
            prev[i] = 0;
        }

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                }
                else
                {
                    curr[j] = 0 + max(prev[j], curr[j - 1]);
                }
            }

            prev = curr;
        }

        return (word1.size() + word2.size()) - (2 * prev[n]);
    }
};