class Solution {
    private:
    int helper(vector<int>& nums, int start, int end)
    {
        int prev2 = 0, prev1 = nums[start];

        for (int i = start + 1; i <= end; ++i)
        {
            int current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }

    public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        
        if (n == 0) 
        {
            return 0;
        }
        if (n == 1)
        {
            return nums[0];
        }
        else
        {
            return max(helper(nums, 0, n-2), helper(nums, 1, n-1));
        }
    }
};