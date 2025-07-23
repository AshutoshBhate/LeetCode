//Why is there a PreSumMap[0]++;

/*
Consider the input nums = [3, 4] and k = 7.
The subarray [3, 4] sums to 7. The correct answer is 1.
Your code calculates a PrefixSum of 7 when it reaches the end of the subarray.
It then looks for remove = PrefixSum - k, which is 7 - 7 = 0.
It checks the map for the count of the prefix sum 0 (PreSumMap[0]). Since the map is 
empty, this returns 0, and the subarray is not counted.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int array_size = nums.size(); //Size of the given array
        unordered_map<int, int> PreSumMap;
        int PrefixSum = 0, count = 0;

        PreSumMap[0] = 1; 

        for (int i = 0; i < array_size; i++) {
            // add current element to prefix Sum:
            PrefixSum += nums[i];

            // Calculate x-k:
            int remove = PrefixSum - k;

            // Add the number of subarrays to be removed:
            count += PreSumMap[remove];

            // Update the count of prefix sum in the map, does 1 if new
            PreSumMap[PrefixSum]++;
        }
        return count;
    }
};

//TC: O(N * (If using map log : N))
//    O(N * (If using unordered_map : N)) worst time if we have a lot of collisions, O(N * (If using unordered_map : 1)) if no collisions
//SC: O(N)