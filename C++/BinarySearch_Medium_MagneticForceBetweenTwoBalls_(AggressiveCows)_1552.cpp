class Solution {
public:

    bool canFit(vector<int>& array, int distance, int numberOfBalls)
    {
        int currNumberBalls = 1, last = array[0];

        for(int i = 0; i < array.size(); i++)
        {
            if(array[i] - last >= distance)
            {
                currNumberBalls++;
                last = array[i];
            }
        }

        if(currNumberBalls < numberOfBalls)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    int maxDistance(vector<int>& position, int m) 
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        sort(position.begin(), position.end());

        int left = 1, right = position[position.size() - 1], max_Count = INT_MIN;

        while(left <= right)
        {
            int mid = int((left + right) / 2);

            if(canFit(position, mid, m) == false)
            {
                right = mid - 1;
            }
            else
            {
                max_Count = max(mid, max_Count);
                left = mid + 1;
            }
        }

        return max_Count;
    }
};