class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> matrix;

        for(int i = 0; i < pow(2, nums.size()); i++) //1<<n = 2^n
        {
            vector<int> subset;

            for (int j = 0; j < nums.size(); j++)
            {
                if (i & (1 << j))
                {
                    subset.push_back(nums[j]);
                }
            }
            matrix.push_back(subset);
        }

        return matrix;
    }
};