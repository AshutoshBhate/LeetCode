//Memoization : 

//Style A : Cannot be mapped to Tabulation directly:

//As we are going from 0 to n - 1, the additional base cases aren't needed (The 0th element might have a negative sign, etc.)

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

//Here as we are coming from n - 1 to 0, we need additional checks for checking whether the 0th element might have minus sign

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

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        
        int n = nums.size();
        
        int totSum = 0;

        for(auto it : nums)
        {
            totSum += it;
        }

        if(totSum - target < 0 || (totSum - target) % 2)
        {
            return 0;
        }
        
        int sum = (totSum - target) / 2;

        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        if(nums[0] == 0)
        {
            dp[0][0] = 2; 
        }
        else
        {
            dp[0][0] = 1; // only Not Pick
            if(nums[0] <= sum)
            {
                dp[0][nums[0]] = 1; // pick
            }
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                //Not Pick
                int notPick = dp[i - 1][j];
        
                //Pick
                int pick = 0;
                if(nums[i] <= j)
                {
                    pick = dp[i - 1][j - nums[i]];
                }
        
                dp[i][j] = (pick + notPick); 
            }
        }
        
        return dp[n - 1][sum];
    }
};

//Space Optimization : 

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        
        int n = nums.size();
        
        int totSum = 0;

        for(auto it : nums)
        {
            totSum += it;
        }

        if(totSum - target < 0 || (totSum - target) % 2)
        {
            return 0;
        }
        
        int sum = (totSum - target) / 2;

        vector<int> prev(sum + 1, 0);
        vector<int> curr(sum + 1, 0);

        if(nums[0] == 0)
        {
            prev[0] = 2; 
        }
        else
        {
            prev[0] = 1; // only Not Pick
            if(nums[0] <= sum)
            {
                prev[nums[0]] = 1; // pick
            }
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                //Not Pick
                int notPick = prev[j];
        
                //Pick
                int pick = 0;
                if(nums[i] <= j)
                {
                    pick = prev[j - nums[i]];
                }
        
                curr[j] = (pick + notPick); 
            }

            prev = curr;
        }
        
        return prev[sum];
    }
};