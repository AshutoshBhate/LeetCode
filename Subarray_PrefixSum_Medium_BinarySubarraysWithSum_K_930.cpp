class Solution {
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal)
        {
            cin.tie(nullptr);
            cout.tie(nullptr);
            ios::sync_with_stdio(false);
    
            int array_size = nums.size();
            unordered_map<int, int> mpp;
            int preSum = 0, count = 0;
    
            mpp[0] = 1; // Setting 0 in the map (Essential)
    
            for (int i = 0; i < array_size; i++)
            {
                // Add current element to prefix Sum:
                preSum += nums[i];
    
                // Calculate x-k:
                int remove = preSum - goal;
    
                // Add the number of subarrays to be removed:
                count += mpp[remove];
    
                // Update the count of prefix sum in the map, does 1 if new
                mpp[preSum]++;
            }
    
            return count;    
        }
    };