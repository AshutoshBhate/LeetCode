//Memoization : 

//Style A : Cannot be mapped to Tabulation directly:

class Solution {
public:

    int helper(int index, vector<int>& nums, int target, int sum, vector<vector<int>>& dp, int offSet)
    {
        if(index == nums.size() && target == sum)
        {
            return 1;
        }
        if(index == nums.size())
        {
            return 0;
        }
        if(index < 0)
        {
            return 0;
        }

        int dpIndex = sum + offSet;

        if(dp[index][dpIndex] != -1)
        {
            return dp[index][dpIndex];
        }

        int minus = helper(index + 1, nums, target, sum - nums[index], dp, offSet);

        int plus = helper(index + 1, nums, target, sum + nums[index], dp, offSet);

        dp[index][dpIndex] = minus + plus;

        return dp[index][dpIndex];
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        int n = nums.size();

        int offSet = 0;

        for(auto it : nums)
        {
            offSet += it;
        }

        vector<vector<int>> dp(n + 1, vector<int>(2 * (offSet + 1), -1));

        int sum = 0;

        return helper(0, nums, target, sum, dp, offSet);
    }
};

//Style B : Can be mapped to Tabulation directly:

class Solution {
public:

    int helper(int index, vector<int>& nums, int target, int offSet, vector<vector<int>>& dp)
    {
        if(index == 0)
        {
            if (nums[0] == 0 && target == 0) 
            {
                return 2;
            }
            if(target == nums[0] || target == -nums[0])
            {
                return 1;
            }
           
            return 0;
        }

        int newTarget = target + offSet;

        if (newTarget < 0 || newTarget >= 2 * offSet + 1)
        {
            return 0;
        }

        if(dp[index][newTarget] != -1)
        {
            return dp[index][newTarget];
        }

        int Minus = helper(index - 1, nums, target + nums[index], offSet, dp);

        int Plus = helper(index - 1, nums, target - nums[index], offSet, dp);

        dp[index][newTarget] = Minus + Plus;
        return dp[index][newTarget];
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        int n = nums.size();

        int offSet = 0;

        for(auto it : nums)
        {
            offSet += it;
        }

        if(abs(target) > offSet)
        {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(2 * offSet + 1, -1));

        return helper(n - 1, nums, target, offSet, dp);
    }
};

//Tabulation : 

