class Solution {
    public:
        int rob(vector<int>& nums)
        {
            int prev2 = 0, prev1 = nums[0];
    
            for (int i = 1; i < nums.size(); ++i)
            {
                int current = max(prev1, prev2 + nums[i]);
                prev2 = prev1;
                prev1 = current;
            }
    
            return prev1;
        }
    };