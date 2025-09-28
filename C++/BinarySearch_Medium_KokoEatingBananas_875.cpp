class Solution {
public:

    int findMax(vector<int> &v)
    {
        long long maxi = INT_MIN;
        long long n = v.size();
        // Find the maximum:
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, (long long)v[i]); // Explicit cast to long long
        }

        return maxi;
    }

    long long calculateTotalHours(vector<int> &v, int hourly)
    {
        long long totalH = 0;
        long long n = v.size();
        // Find total hours:
        for (int i = 0; i < n; i++)
        {
            totalH += (v[i] + hourly - 1) / hourly; // Integer division with ceiling
        }

        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        long long low = 1, high = findMax(piles);

        // Apply binary search:
        while (low <= high)
        {
            long long mid = (low + high) / 2;
            long long totalH = calculateTotalHours(piles, mid);
            if (totalH <= h)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
