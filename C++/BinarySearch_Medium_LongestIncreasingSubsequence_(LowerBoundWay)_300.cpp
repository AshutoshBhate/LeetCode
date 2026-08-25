class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> temp = {INT_MIN};
        int count = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
                count++;
            }
            else
            {
                temp[lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin()] = nums[i];
            }
        }   

        return count; 
    }
};