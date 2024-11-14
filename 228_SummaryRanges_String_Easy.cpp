class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> answer;
        bool continue_flag = false;
        string backtrack;

        if(nums.size() == 0)
        {
            return answer;
        }
        
        nums.push_back(2^32);

        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i + 1] != (static_cast<long>(nums[i]) + 1) && continue_flag == false)
            {
                answer.push_back(to_string(nums[i]));
            }
            if(nums[i + 1] == static_cast<long>(nums[i]) + 1 && continue_flag == false)
            {
                continue_flag = true;
                backtrack = to_string(nums[i]);
            }
            if(nums[i + 1] == static_cast<long>(nums[i]) + 1 && continue_flag == true)
            {
                continue;
            }
            if(nums[i + 1] != static_cast<long>(nums[i]) + 1 && continue_flag == true)
            {
                answer.push_back(backtrack + "->" + to_string(nums[i]));
                continue_flag = false;
            }
        }

        return answer;
    }
};