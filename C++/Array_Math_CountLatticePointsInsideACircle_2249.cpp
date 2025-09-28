class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        set<pair<int, int>> lattices;

        for (const auto& temp : circles)
        {
            int x = temp[0];
            int y = temp[1];
            int r = temp[2];

            for (int px = x - r; px <= x + r; px++)
            {
                for (int py = y - r; py <= y + r; py++)
                {
                    if ((px - x) * (px - x) + (py - y) * (py - y) <= r * r)
                    {
                        lattices.insert({px, py});
                    }
                }
            }
        }
        
        return lattices.size();
    }
};