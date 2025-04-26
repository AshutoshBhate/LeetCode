class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        //Time Complexity for for loop is O(n) and average case unordered_map is O(log n) (Worst case for collisions is O(n)) so: If simple map:
        //O(n * log n), For unordered_map, best case will be O(1). Depends on what complexity you assume for the map

        //Space complexity for worst case is O(n)
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int array_size = nums.size(); //Size of the given array
        unordered_map<int, int> mpp;
        int preSum = 0, count = 0;

        mpp[0] = 1; // Setting 0 in the map

        for (int i = 0; i < array_size; i++) {
            // add current element to prefix Sum:
            preSum += nums[i];

            // Calculate x-k:
            int remove = preSum - k;

            // Add the number of subarrays to be removed:
            count += mpp[remove];

            // Update the count of prefix sum in the map, does 1 if new
            mpp[preSum]++;
        }
        return count;
    }
};