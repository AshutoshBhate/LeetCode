class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        vector<int> rotated_array(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            rotated_array[(i + k) % nums.size()] = nums[i];
        }

        nums.clear();

        nums = rotated_array;
    }
};