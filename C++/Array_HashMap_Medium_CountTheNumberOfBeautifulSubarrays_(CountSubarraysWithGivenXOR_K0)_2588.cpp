class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        long long masterCount = 0;
        unordered_map<int, int> XORMap;
        long long XORSum = 0;

        XORMap[0] = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            XORSum = XORSum ^ nums[i];

            int remove = XORSum ^ 0;

            masterCount += XORMap[remove];

            XORMap[XORSum]++;
        }

        return masterCount;
    }
};