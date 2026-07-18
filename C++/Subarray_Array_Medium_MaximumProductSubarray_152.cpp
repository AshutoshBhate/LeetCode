class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int maxCount = nums[0];
        int count_p = nums[0];
        int count_n = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            int curr = nums[i];
            int temp = count_p;

            count_p = max(curr, max(temp*curr, count_n*curr));
            count_n = min(curr, min(temp*curr, count_n*curr));

            maxCount = max(count_p, maxCount);
        }

        return maxCount;
    }
};