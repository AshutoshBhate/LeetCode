class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int timeadd = 0, total_time = 0;

        for(int i = 0; i < timeSeries.size() - 1; i++)
        {
            if((timeSeries[i] + duration) > timeSeries[i + 1])
            {
                timeadd = timeSeries[i + 1] - timeSeries[i];
                total_time += timeadd;
            }
            else
            {
                total_time += duration;
            }
        }
        total_time += duration;

        return total_time;
    }
};