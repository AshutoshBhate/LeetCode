//ChatGPT Solution : 

class Solution {
public:
    int jump(vector<int>& nums)
    {
        int n = nums.size();

        int jumpsCount = 0;
        int currentLimit = 0;
        int nextLimit = 0;

        for (int index = 0; index < n - 1; index++)
        {
            nextLimit = max(nextLimit, index + nums[index]);

            if (index == currentLimit)
            {
                jumpsCount++;
                currentLimit = nextLimit;
            }
        }
        
        return jumpsCount;
    }
};