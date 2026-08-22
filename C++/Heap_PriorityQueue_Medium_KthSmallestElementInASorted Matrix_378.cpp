class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for(int i = 0; i < matrix.size(); i++)
        {
            pq.push({matrix[i][0], i, 0});
        }

        for(int i = 1; i < k; i++)
        {
            auto curr = pq.top();
            pq.pop();

            int r = curr[1];
            int c = curr[2];

            if(c + 1 < matrix[0].size())
            {
                pq.push({matrix[r][c + 1], r, c + 1});
            }
        }

        return pq.top()[0];
    }
};