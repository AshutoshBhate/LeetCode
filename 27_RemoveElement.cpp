class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int initial_size = nums.size();
        auto it = remove(nums.begin(), nums.end(), val);
        nums.erase(it, nums.end()); 
        int new_size = nums.size();

        return initial_size - (initial_size - new_size);   
    }
};