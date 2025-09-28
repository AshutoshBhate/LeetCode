//Memoization : 

class Solution {
public:

    bool helper(int index, vector<int>& nums, int target, vector<vector<int>>& dp)
    {
        if(target == 0)
        {
            return true;
        }
        if(index < 0)
        {
            return false;
        }
        if(index == 0)
        {
            return nums[0] == target;
        }

        if(dp[index][target] != -1)
        {
            return dp[index][target];
        }

        bool nonTake = false, Take = false;

        nonTake = helper(index - 1, nums, target, dp);

        if(nums[index] <= target)
        {
            Take = helper(index - 1, nums, target - nums[index], dp);
        }
        
        dp[index][target] = nonTake || Take;
        return dp[index][target];
    }

    bool canPartition(vector<int>& nums)
    {
        int n = nums.size();
        int totSum = 0;

        for(int i = 0; i < n; i++)
        {
            totSum += nums[i];
        }

        if(totSum % 2 != 0)
        {
            return false;
        }

        int halfSum = totSum/2;

        vector<vector<int>> dp(n, vector<int>(halfSum + 1, -1));

        return helper(n - 1, nums, halfSum, dp);    
    }
};

//TC: O(N * halfSum)
//SC: O(N * halfSum) + O(N)

//Tabulation : 

class Solution {
public:

    bool canPartition(vector<int>& nums)
    {
        int n = nums.size();
        int totSum = 0;

        for(int i = 0; i < n; i++)
        {
            totSum += nums[i];
        }

        if(totSum % 2 != 0)
        {
            return false;
        }

        int halfSum = totSum/2;

        vector<vector<int>> dp(n, vector<int>(halfSum + 1, 0));

        for(int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        if(nums[0] <= halfSum)
        {
            dp[0][nums[0]] = true;
        }

        for(int i = 1; i < n; i++)
        {
            for (int target = 1; target <= halfSum; target++)
            {
                bool Take = false;

                bool nonTake = dp[i - 1][target];

                if(nums[i] <= target)
                {
                    Take = dp[i - 1][target - nums[i]];
                }

                dp[i][target] = nonTake || Take;
            }
        }

        return dp[n - 1][halfSum];    
    }
};

//TC: O(N * halfSum)
//SC: O(N * halfSum)

//Space Optimized : 

class Solution {
public:

    bool canPartition(vector<int>& nums)
    {
        int n = nums.size();
        int totSum = 0;

        for(int i = 0; i < n; i++)
        {
            totSum += nums[i];
        }

        if(totSum % 2 != 0)
        {
            return false;
        }

        int halfSum = totSum/2;

        vector<int> prev(halfSum + 1, 0);
        vector<int> curr(halfSum + 1, 0);

        prev[0] = 1;

        if(nums[0] <= halfSum)
        {
            prev[nums[0]] = true;
        }

        for(int i = 1; i < n; i++)
        {
            curr[0] = 1;
            for (int target = 1; target <= halfSum; target++)
            {
                bool Take = false;

                bool nonTake = prev[target];

                if(nums[i] <= target)
                {
                    Take = prev[target - nums[i]];
                }

                curr[target] = nonTake || Take;
            }

            prev = curr;
        }

        return prev[halfSum];    
    }
};

//TC: O(N * halfSum)
//SC: O(halfSum)