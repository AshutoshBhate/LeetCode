class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int left = 0, right = nums.size() - 1, mid;

        while(left <= right)
        {
            mid = (left + right) / 2;
            
            if(mid == 0 || mid == nums.size() - 1)
            {
                return nums[mid];
            }

            if(nums[mid - 1] == nums[mid])
            {
                if((abs(left - (mid - 1)) % 2 != 0))
                {
                    right = mid - 2;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else if(nums[mid + 1] == nums[mid])
            {
                if((abs(right - (mid + 1))) % 2 != 0)
                {
                    left = mid + 2;
                }
                else
                {
                    right  = mid - 1;
                }
            }
            else
            {
                return nums[mid];
            }
        }

        return nums[mid];
    }
};