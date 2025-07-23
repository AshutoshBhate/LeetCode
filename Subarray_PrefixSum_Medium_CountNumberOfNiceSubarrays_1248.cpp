class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        unordered_map<int, int> PreSumMap;

        PreSumMap[0]++;

        int PrefixSum = 0, count = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            PrefixSum += (nums[i] % 2);
            int remove = PrefixSum - k;

            count += PreSumMap[remove];   //Counts how many previous subarrays satisfy remove

            PreSumMap[PrefixSum]++;
        }

        return count;
    }
};