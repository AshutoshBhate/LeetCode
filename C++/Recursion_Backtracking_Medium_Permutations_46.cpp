// Solution using a visited_array:

class Solution {
public:

    void helper(vector<int>& nums, vector<vector<int>>& result, vector<int>& ds, vector<int>& visited_array)
    {
        if(ds.size() == nums.size())
        {
            result.push_back(ds);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(!visited_array[i])
            {
                ds.push_back(nums[i]);
                visited_array[i]++;
                helper(nums, result, ds, visited_array);
                ds.pop_back();
                visited_array[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {   
        vector<vector<int>> result;
        vector<int> ds;
        vector<int> visited_array(nums.size(), 0);

        helper(nums, result, ds, visited_array);

        return result;
        
    }
};

// Solution using swapping:

class Solution {
public:

    void helper(vector<int>& nums, int index, vector<vector<int>>& answer)
    {
        if(index == nums.size())
        {
            answer.push_back(nums); 
            return;
        }

        for(int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            helper(nums, index + 1, answer);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        int index = 0;

        vector<vector<int>> answer;

        helper(nums, index, answer);

        return answer;
    }
};



