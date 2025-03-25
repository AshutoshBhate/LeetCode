class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> check_array(0);
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = find(check_array.begin(), check_array.end(), nums[i]);
            if(iter == check_array.end())
            {
                 check_array.push_back(nums[i]);
            }
            else
            {
                auto it = remove(check_array.begin(), check_array.end(), nums[i]);
                check_array.erase(it, check_array.end());
            }
        }
        return check_array[0];
    }
};