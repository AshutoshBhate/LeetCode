//Striver Solution for non Negative integer input : 

class Solution {
public:
    int minimumDifference(vector<int>& nums)
    {
        int n = nums.size();

        int totSum = 0;

        for(int i = 0; i < n; i++)
        {
            totSum += nums[i];
        }

        int k = totSum;

        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
        
        for(int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        
        if(n > 0 && nums[0] <= k)
        {
            dp[0][nums[0]] = true;
        }
        
        for(int i = 1; i < n; i++)
        {
            for(int target = 1; target <= k; target++)
            {
                bool notTake = dp[i - 1][target];
                
                bool Take = false;
        
                if(nums[i] <= target)
                {
                    Take = dp[i - 1][target - nums[i]];
                }
                
                dp[i][target] = notTake || Take;
            }
        }
        
        //dp[n - 1][col -> 0,...,totSum]
        int mini = 1e9;

        for(int s1 = 0; s1 <= totSum/2; s1++)
        {
            if(dp[n - 1][s1] == true)
            {
                mini = min(mini, abs((totSum - s1) - s1));
            }
        }

        return mini;

    }
};

//Actual LeetCode Solution : 

class Solution {
public:
    int minimumDifference(vector<int>& nums)
    {
        int totalSize = nums.size();
        int halfSize = totalSize / 2;

        long long grandTotal = 0;
        for (int v : nums)
        {
            grandTotal += v;
        }

        // Split into two halves
        vector<int> leftHalf(nums.begin(), nums.begin() + halfSize);
        vector<int> rightHalf(nums.begin() + halfSize, nums.end());

        // sumsLeft[k] will hold all sums of subsets of size k in leftHalf
        // sumsRight[k] similarly for rightHalf
        vector<vector<long long>> sumsLeft(halfSize + 1);
        vector<vector<long long>> sumsRight(halfSize + 1);

        // Enumerate all subsets of 'leftHalf'
        for (int subsetMask = 0; subsetMask < (1 << halfSize); subsetMask++)
        {
            long long subsetSum = 0;
            int bitsCount = 0;

            for (int i = 0; i < halfSize; i++)
            {
                if (subsetMask & (1 << i))
                {
                    subsetSum += leftHalf[i];
                    bitsCount++;
                }
            }

            sumsLeft[bitsCount].push_back(subsetSum);
        }

        // Enumerate all subsets of 'rightHalf'
        for (int subsetMask = 0; subsetMask < (1 << halfSize); subsetMask++)
        {
            long long subsetSum = 0;
            int bitsCount = 0;

            for (int i = 0; i < halfSize; i++)
            {
                if (subsetMask & (1 << i))
                {
                    subsetSum += rightHalf[i];
                    bitsCount++;
                }
            }

            sumsRight[bitsCount].push_back(subsetSum);
        }

        // Sort each list of right-half sums for binary search
        for (int k = 0; k <= halfSize; k++)
        {
            sort(sumsRight[k].begin(), sumsRight[k].end());
        }

        long long bestDiff = LLONG_MAX;

        // Try taking leftCount from leftHalf, and (halfSize - leftCount) from rightHalf
        for (int leftCount = 0; leftCount <= halfSize; leftCount++)
        {
            for (long long leftSum : sumsLeft[leftCount])
            {
                // We want leftSum + rightSum ≈ grandTotal/2 
                // ⇒ rightSum ≈ grandTotal/2 - leftSum
                long long desiredRight = grandTotal / 2 - leftSum;
                auto& rightList = sumsRight[halfSize - leftCount];

                // find first element >= desiredRight
                auto lower = lower_bound(rightList.begin(), rightList.end(), desiredRight);

                // check this element and the one before it
                for (int offset = -1; offset <= 0; offset++)
                {
                    auto candidate = (offset == -1
                                      ? (lower == rightList.begin() ? rightList.end() : lower - 1)
                                      : lower);

                    if (candidate != rightList.end())
                    {
                        long long rightSum = *candidate;
                        long long subsetTotal = leftSum + rightSum;
                        long long otherTotal = grandTotal - subsetTotal;
                        long long diff = llabs(subsetTotal - otherTotal);
                        bestDiff = min(bestDiff, diff);
                    }
                }
            }
        }

        return bestDiff;
    }
};


