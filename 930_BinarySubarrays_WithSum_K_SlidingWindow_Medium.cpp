class Solution {
public:

    int lessthangoal(vector<int>& array, int target)
    {
        if(target < 0)
        {
            return 0;
        }
        int l = 0, r = 0, sum = 0, count = 0;
        while(r < array.size())
        {
            sum = sum +  array[r];
            while(sum > target)
            {
                sum = sum - array[l];
                l = l + 1;
            }
            count = count + (r - l + 1);
            r = r + 1;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        return (lessthangoal(nums, goal) - lessthangoal(nums, goal - 1));
    }
};