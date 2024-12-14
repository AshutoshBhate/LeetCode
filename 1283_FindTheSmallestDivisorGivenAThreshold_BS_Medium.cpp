class Solution {
public:

    long getResult(vector<int>& vec, long number)
    {
        long result = 0;

        for(int i = 0; i < vec.size(); i++)
        {
            result = result + (ceil((double)vec[i] / (double)number));
        }

        return result;
    }

    int smallestDivisor(vector<int>& nums, int threshold)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios :: sync_with_stdio(false);

        int i = 1, j = *(max_element(nums.begin(), nums.end())), min_int = INT_MAX;

        while(i <= j)
        {
            int mid = (i + j)/2;
            if(getResult(nums, mid) > threshold)
            {
                i = mid + 1;
            }
            else
            {
                min_int = min(min_int, mid);
                j = mid - 1;
            }
        }

        return min_int;
    }
};