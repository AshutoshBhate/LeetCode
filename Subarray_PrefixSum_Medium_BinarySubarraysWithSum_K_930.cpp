class Solution {
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal)
        {
            int array_size = nums.size();
            unordered_map<int, int> PreSumMap;
            int prefixSum = 0, count = 0;
    
            PreSumMap[0]++; 
    
            for (int i = 0; i < array_size; i++)
            {
                // Add current element to prefix Sum:
                prefixSum += nums[i];
    
                // Calculate x-k:
                int remove = prefixSum - goal;
    
                // Add the number of subarrays to be removed:
                count += PreSumMap[remove];
    
                // Update the count of prefix sum in the map, does 1 if new
                PreSumMap[prefixSum]++;
            }
    
            return count;    
        }
    };