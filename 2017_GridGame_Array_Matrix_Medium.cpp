class Solution {
public:
    long long gridGame(vector<vector<int>>& grid)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        long long minimum = LONG_MAX;
        int columns = grid[0].size();
        long long uppersum = 0;
        long long lowersum = 0; 

        for(int i = 0; i < columns; i++)
        {
            uppersum += grid[0][i];
        }

        for(int i = 0; i < columns; i++)
        {
            uppersum -= grid[0][i];
            minimum = min(minimum, max(uppersum, lowersum));
            lowersum += grid[1][i];
        }

        return minimum;
    }
};