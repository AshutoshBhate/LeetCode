class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        auto it = find(nums.begin(), nums.end(), target);
        if(it != nums.end())
        {
            return (it - nums.begin());
        }
        else
        {
            nums.push_back(target);
            sort(nums.begin(), nums.end());
            auto iter = find(nums.begin(), nums.end(), target);
            return (iter - nums.begin());
        }
    }
};