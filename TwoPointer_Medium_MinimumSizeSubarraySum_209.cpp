class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int left = 0, min_Length = INT_MAX, current_sum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            current_sum += nums[i];

            if(current_sum > target)
            {
                while(current_sum > target)
                {
                    current_sum -= nums[left];
                    min_Length = min(min_Length, i - left + 1);
                    left++;
                }
            }
            
            if(current_sum == target)
            {
                min_Length = min(min_Length, i - left + 1);
            }
        }

        return min_Length == INT_MAX ? 0 : min_Length;
    }
};