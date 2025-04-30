//ChatGPT Solution : 

class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int maxReach = 0;

        for (int pos = 0; pos < nums.size(); pos++)
        {
            if (pos > maxReach)
            {
                return false;
            }
            maxReach = max(maxReach, pos + nums[pos]);
        }
        
        return true;
    }
};