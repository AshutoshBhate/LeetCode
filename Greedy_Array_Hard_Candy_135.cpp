class Solution {
public:
    int candy(vector<int>& ratings)
    {
        int n = ratings.size();

        int totalCandies = 1;
        int up = 0;
        int down = 0;
        int prevSlope = 0;

        for (int i = 1; i < n; i++)
        {
            int currSlope = ratings[i] > ratings[i - 1] ? 1 : (ratings[i] < ratings[i - 1] ? -1 : 0);
            if ((prevSlope > 0 && currSlope == 0) || (prevSlope < 0 && currSlope >= 0))
            {
                totalCandies += up * (up + 1) / 2 + down * (down + 1) / 2 + max(up, down);
                up = 0;
                down = 0;
            }

            if (currSlope > 0)
            {
                up++;
            }
            else if (currSlope < 0)
            {
                down++;
            }
            else
            {
                totalCandies++;
            }
            prevSlope = currSlope;
        }

        totalCandies += up * (up + 1) / 2 + down * (down + 1) / 2 + max(up, down);

        return totalCandies;
    }
};