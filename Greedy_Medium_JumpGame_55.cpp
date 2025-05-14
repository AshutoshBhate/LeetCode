class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int maxReachable = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(maxReachable >= i)
            {
                maxReachable = max(maxReachable, nums[i] + i);
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};