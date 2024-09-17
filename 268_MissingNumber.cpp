class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        vector<int> perfect_array(0);

        
        int biggest_element = nums.size();
        for(int i = 0; i <= biggest_element; i++)
        {
            perfect_array.push_back(i);
        }
        int perfect_sum = accumulate(perfect_array.begin(), perfect_array.end(), 0);
        int sum = accumulate(nums.begin(), nums.end(), 0);

        return perfect_sum - sum;
    }
};