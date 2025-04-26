class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        unordered_map<int, int> mpp;

        mpp[0]++;

        int PrefixSum = 0, count = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            PrefixSum += (nums[i] % 2);
            int remove = PrefixSum - k;

            count += mpp[remove];   //Counts how many previous subarrays satisfy remove

            mpp[PrefixSum]++;
        }

        return count;
    }
};