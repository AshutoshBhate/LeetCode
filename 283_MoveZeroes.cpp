class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int counter = 0;
        int initial_size = nums.size();
        for(int i = 0; i < initial_size; i++)
        {
            if(nums[i] == 0)
            {
                counter++;
                nums.push_back(0);
            }
            else
            {
                continue;
            }
        } 
        auto iter = remove(nums.begin(), nums.end() - counter, 0);
        nums.erase(iter, nums.end() - counter);
    }
};
