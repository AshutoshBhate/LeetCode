//BackTracking (More Efficient)

class Solution 
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end()); // Sort to bring duplicates together
        backtrack(0, nums, subset, result);
        return result;
    }

    void backtrack(int start, vector<int>& nums, vector<int>& subset, vector<vector<int>>& result)
    {
        // Add the current subset to the result
        result.push_back(subset);

        // Iterate through the numbers starting from 'start' index
        for (int i = start; i < nums.size(); ++i)
        {
            // Skip duplicates: if the current number is the same as the previous, skip it
            if (i > start && nums[i] == nums[i - 1])
            {
                continue;
            }

            // Include nums[i] in the current subset
            subset.push_back(nums[i]);
            
            // Recurse with next index
            backtrack(i + 1, nums, subset, result);
            
            // Backtrack: remove the last added element
            subset.pop_back();
        }
    }
};


//BitMasking + Set (Less Efficient)

class Solution 
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> result;
        set<vector<int>> unique; // Set to automatically handle duplicate subsets
        sort(nums.begin(), nums.end()); // Sort to group duplicates together
        
        int n = nums.size();
        
        // Iterate over all possible bitmasks (2^n)
        for (int i = 0; i < (1 << n); ++i)
        {
            vector<int> subset;
            
            // For each bit position, decide whether to include nums[j]
            for (int j = 0; j < n; ++j)
            {
                if (i & (1 << j))
                {
                    subset.push_back(nums[j]);
                }
            }
            
            // Insert subset into set to avoid duplicates
            unique.insert(subset);
        }

        // Transfer subsets from set to result vector
        for (auto &s : unique)
        {
            result.push_back(s);
        }
        
        return result;
    }
};
