class Solution {
public:

    int computeDays(vector<int>& vec, int mid)
    {
        int days_count = 0, addition = 0;

        for(int i = 0; i < vec.size(); i++)
        {
            if(addition + vec[i] > mid)
            {
                addition = vec[i];
                days_count++;
            }
            else
            {
                addition += vec[i];
            }
        }
        
        return days_count + 1;
    }

    int shipWithinDays(vector<int>& weights, int days)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int addition = 0, maxi = INT_MIN, mid, mid_final = INT_MAX;

        for(int i = 0; i < weights.size(); i++)
        {
            addition += weights[i];
            maxi = max(maxi, weights[i]);
        }

        int l = maxi, r = addition;

        while(l <= r)
        {

            mid = (l + r)/2;

            if(computeDays(weights, mid) <= days)
            {
                r = mid - 1;
                mid_final = min(mid_final, mid);
            }
            else
            {
                l = mid + 1;
            }
        }

        return mid_final;
    }
};