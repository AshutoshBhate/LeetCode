//Memoization:

class Solution {
    public:
    
        int helper(vector<int>& nums, vector<int>& dp, int index)
        {
            if(index == 0)
            {
                return nums[0];
            }
            
            if(dp[index] != -1)
            {
                return dp[index];
            }
    
            int take = INT_MIN;
    
            if(index >= 2)
            {
                take = nums[index] + helper(nums, dp, index - 2);
            }
            
            int non_take = 0 + helper(nums, dp, index - 1);
    
            dp[index] = max(take, non_take);
            return dp[index];
        }
    
        int rob(vector<int>& nums)
        {
            int n = nums.size();
    
            vector<int> dp(n, -1);
    
            return helper(nums, dp, n - 1);
        }
};

//TC : O(N)
//SC : O(N) + O(N)  StackSpace and Array

//Tabuation:

class Solution {
    public:

        int rob(vector<int>& nums)
        {
            int n = nums.size();

            if(n == 0)
            {
                return 0;
            }
            if(n == 1)
            {
                return nums[0];
            }

            vector<int> dp(n, 0);
            dp[0] = nums[0];

            for(int i = 1; i < n; i++)
            {
                int take = nums[i];

                if(i > 1)
                {
                    take += dp[i - 2];
                }

                int non_take = 0 + dp[i - 1];

                dp[i] = max(take, non_take);
            }

            return dp[n - 1];
        }
};

//TC : O(N)
//SC : O(N)

//Space Optimisation:

class Solution {
    public:
        int rob(vector<int>& nums)
        {
            int n = nums.size();
    
            int prev = nums[0];
            int prev2 = 0;
    
            for(int i = 1; i < n; i++)
            {
                int take = nums[i];
    
                if(i > 1)
                {
                    take += prev2;
                }
    
                int non_take = 0 + prev;
    
                int curr_index = max(take, non_take);
                prev2 = prev;
                prev = curr_index;
            }   
    
            return prev;
        }
};

//TC : O(N)
//SC : O(1)


