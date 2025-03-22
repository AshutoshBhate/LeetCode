class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution_array(0);
        bool flag = false;

        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target && i != j)
                {
                    solution_array.push_back(i);
                    solution_array.push_back(j);
                    flag = true;
                }
                if(flag == true)
                {
                    break;
                }
            }
            if(flag == true)
            {
                break;
            }
        }

        return solution_array;
        
    }
};