class Solution {
public:
    bool check(vector<int>& nums) 
    {
        //vector<int> sorted_nums(nums.size());
        //vector<int> check_array(nums.size());
        int ascend_breaker = -1;
        bool ascend_break_flag = false;
        //int maxElement = nums[0];

        //copy(nums.begin(), nums.end(), sorted_nums.begin());
        //sort(sorted_nums.begin(), sorted_nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > nums[(i+1) % nums.size()])
            {
                if (ascend_break_flag == true)
                    return false;
                else
                {
                    ascend_breaker = (i+1) % nums.size();
                    ascend_break_flag = true;
                }
            }
            //maxElement = max(maxElement, nums[i]);
        } 
        return true;
/*
        if (ascend_breaker == -1)
            return true;

        for (int i = ascend_breaker; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i+1])
            {
                return false;
            }
            //maxElement = max(maxElement, nums[i]);
        } 

        if (nums[nums.size() - 1] > nums[0])
            return false;
        else
            return true;
          

        for(int i = 0; i < nums.size(); i++)
        {
            check_array[(i+ascend_breaker) % nums.size()] = sorted_nums[i];
        }

        if(check_array == nums)
        {
            return true;
        }
        else
        {
            return false;
        }
        */
    }
};