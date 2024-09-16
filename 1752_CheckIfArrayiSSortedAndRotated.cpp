class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> sorted_nums(nums.size());
        vector<int> check_array(nums.size());
        int ascend_breaker = 0;
        int maxElement = nums[0];

        copy(nums.begin(), nums.end(), sorted_nums.begin());
        sort(sorted_nums.begin(), sorted_nums.end());

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i+1])
            {
                ascend_breaker = i + 1;
            }
            //maxElement = max(maxElement, nums[i]);
        }   

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
    }
};