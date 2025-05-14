class Solution {
public:
    int jump(vector<int>& nums)
    {
        int jumps = 0;
        int maxReachable = 0;
        int currEnd = 0;

        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(i + nums[i] > maxReachable)
            {
                maxReachable = i + nums[i];
            }
            if(i == currEnd)
            {
                jumps += 1;
                currEnd = maxReachable;
            }
        }

        return jumps;
    }
};