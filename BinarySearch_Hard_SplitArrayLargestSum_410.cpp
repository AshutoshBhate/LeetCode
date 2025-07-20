class Solution {
public:

    int countSubarrays(vector<int>& nums, int mid)
    {
        int curr_Subarray_sum = 0, subarrays = 1;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(curr_Subarray_sum + nums[i] <= mid)
            {
                curr_Subarray_sum += nums[i];
            }
            else
            {
                subarrays++;
                curr_Subarray_sum = nums[i];
            }
        }
        
        return subarrays;
    }

    int splitArray(vector<int>& nums, int k)
    {
        if(k > nums.size())
        {
            return -1;
        }
        
        int low = *(max_element(nums.begin(), nums.end()));   //max_element returns an iterator
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        
        while(low <= high)
        {
            int mid = (low + high) / 2;
            
            if(countSubarrays(nums, mid) <= k)
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