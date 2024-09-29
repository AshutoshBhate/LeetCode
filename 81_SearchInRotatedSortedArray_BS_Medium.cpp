class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int left = 0, right = nums.size() - 1, mid;

        while(left <= right)
        {
            mid = (left + right)/2;
            if(nums[mid] == target)
            {
                return true;
            }
            if(nums[mid] == nums[left] && nums[mid] == nums[right])
            {
                left = left + 1;
                right = right - 1;
                continue;
            }
            if(nums[mid] >= nums[left])
            {
                if(nums[mid] >= target && target >= nums[left])
                {
                    right = mid - 1;
                }
                 else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if(target >= nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};