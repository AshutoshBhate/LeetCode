class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        long count = 0, max_count = 0;
        vector<long> hash_array(nums.size());

        copy(nums.begin(), nums.end(), hash_array.begin());
        
        sort(hash_array.begin(), hash_array.end());
        if(hash_array[hash_array.size() - 1] < 0)
        {
            return hash_array[hash_array.size() - 1];
        }

        for(int i = 0; i < nums.size(); i++)
        {
            count += nums[i];
            if(count < 0)
            {
                count = 0;
                continue;
            }
            else
            {
                if(count > max_count)
                {
                    max_count = count;
                }
            }
        }

        return max_count;
    }
};