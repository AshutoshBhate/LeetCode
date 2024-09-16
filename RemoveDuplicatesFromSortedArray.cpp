class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {

        unordered_set<int> my_set(0);
        for(int element : nums)
        {
            my_set.insert(element);
        }

        nums.clear();

        for(int element : my_set)
        {
            nums.push_back(element);
        }

        sort(nums.begin(), nums.end());

        return nums.size();
        
    }
};