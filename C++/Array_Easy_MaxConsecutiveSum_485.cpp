class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int sub_count = 0, count = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                sub_count++;
            }
            else
            {
                if(sub_count > count)
                {
                    count = sub_count;
                }
                sub_count = 0;
            }
        }
        if(sub_count > count)
        {
            count = sub_count;
        }
        
        return count;
    }
};